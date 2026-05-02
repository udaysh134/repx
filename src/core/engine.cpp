// Headers
#include <iostream>
#include <windows.h>

#include "engine.hpp"
#include "settings.hpp"
#include "utils.hpp"
#include "registry.hpp"

#include "layout.hpp"
#include "navigation.hpp"
#include "state.hpp"
#include "renderer.hpp"

// Constants
#define UPDATE_PARAMS lyt, nav, registry, state, rdr


// ----------------------------------------------------------------------------------------------------
// Engine Main Loop
// ----------------------------------------------------------------------------------------------------

void start() {
    Layout lyt;
    Navigation nav;
    Registry registry;
    State state;
    Renderer rdr;

    bool running = true;

    // Enabeling Window's Events

    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;

    GetConsoleMode(hInput, &mode);
    mode |= ENABLE_WINDOW_INPUT;
    SetConsoleMode(hInput, mode);

    // Initialize the program

    updateFrame(UPDATE_PARAMS);


    // Main Engine loop

    while (running) {
        INPUT_RECORD record;
        DWORD events;

        ReadConsoleInput(hInput, &record, 1, &events);

        switch (record.EventType) {

            // If user tries to navigate within the program ---------------------------------------- >>

            case KEY_EVENT: {
                auto &keyEvent = record.Event.KeyEvent;
                if (!keyEvent.bKeyDown) break;

                int key = keyEvent.wVirtualKeyCode;
                char c = keyEvent.uChar.AsciiChar;

                auto currentPage = nav.current().page;
                const auto &page = registry.getPage(currentPage);
                const auto &items = page.options;

                bool isFooter = false;

                if (!items.empty() && state.index() < items.size()) {
                    isFooter = (items[state.index()].placement == Options::Placement::FOOTER);
                }

                switch (key) {
                    case VK_UP : { // Up Arrow
                        if (items.empty()) break;

                        if (isFooter) {
                            // Jump to last BODY item (if inside Footer)
                            for (int i = items.size() - 1; i >= 0; --i) {
                                if (items[i].placement == Options::Placement::BODY) {
                                    state.setIndex(i);
                                    break;
                                }
                            }
                        } else {
                            state.moveUp(items.size());
                        }

                        updateFrame(UPDATE_PARAMS);
                        break;
                    }


                    case VK_DOWN : { // Down Arrow
                        if (items.empty()) break;

                        if (!isFooter) {
                            bool isLastBody = true;

                            for (int i = state.index() + 1; i < items.size(); ++i) {
                                if (items[i].placement == Options::Placement::BODY) {
                                    isLastBody = false;
                                    break;
                                }
                            }

                            if (isLastBody) {
                                // Jump to first FOOTER item (if inside Body), if exists
                                for (int i = 0; i < items.size(); ++i) {
                                    if (items[i].placement == Options::Placement::FOOTER) {
                                        state.setIndex(i);
                                        break;
                                    }
                                }
                            } else {
                                state.moveDown(items.size());
                            }
                        }

                        updateFrame(UPDATE_PARAMS);
                        break;
                    }

                    case VK_LEFT: { // Left Arrow (for footer)
                        if (isFooter) {
                            for (int i = state.index() - 1; i >= 0; --i) {
                                if (items[i].placement == Options::Placement::FOOTER) {
                                    state.setIndex(i);
                                    break;
                                }
                            }

                            updateFrame(UPDATE_PARAMS);
                        }

                        break;
                    }


                    case VK_RIGHT: { // Right Arrow (for footer)
                        if (isFooter) {
                            for (int i = state.index() + 1; i < items.size(); ++i) {
                                if (items[i].placement == Options::Placement::FOOTER) {
                                    state.setIndex(i);
                                    break;
                                }
                            }

                            updateFrame(UPDATE_PARAMS);
                        }

                        break;
                    }

                    
                    case VK_RETURN : { // Enter
                        if (items.empty()) break;
                        if (state.index() >= items.size()) state.reset();

                        const auto &selected = items[state.index()];

                        if (selected.type == Options::Type::ACTION) {
                            nav.setCursor(state.index());

                            // 1. Get CURRENT page
                            const auto &curPage = registry.getPage(currentPage);

                            // 2. Run action in CURRENT page
                            if (curPage.onAction) curPage.onAction(nav, state, selected);

                            // 3. THEN navigate
                            if (selected.targetPage != PageId::IDLE) {
                                nav.enter(selected.targetPage);

                                const auto &nextPage = registry.getPage(selected.targetPage);
                                if (nextPage.onEnter) {
                                    nextPage.onEnter(nav, state);
                                }
                            }

                            state.reset();
                            updateFrame(UPDATE_PARAMS);
                        } else if (selected.type == Options::Type::INPUT) {
                            const auto& curPage = registry.getPage(currentPage);
                            if (curPage.onInput) curPage.onInput(nav, state, key);

                            state.startEditing();
                            updateFrame(UPDATE_PARAMS);
                        } else if (selected.type == Options::Type::SELECTION) {
                            state.toggleSelection(state.index());
                            updateFrame(UPDATE_PARAMS);
                        }

                        break;
                    }

                    case VK_ESCAPE : { // ESC
                        if (nav.canGoBack()) {
                            nav.back();
                            state.setIndex(nav.cursor());
                            updateFrame(UPDATE_PARAMS);
                        } else {
                            running = false;
                            updateFrame(UPDATE_PARAMS);
                        }

                        break;
                    }
                }

                if (state.isEditing()) {
                    if (key == VK_BACK) {
                        state.removeChar();
                        updateFrame(UPDATE_PARAMS);
                    } else if (c >= 32 && c <= 126) { // only allow characters that can actually be displayed on the screen
                        state.appendChar(c);
                        updateFrame(UPDATE_PARAMS);
                    }
                }

                break;
            }
            

            // If user resizes the program window ---------------------------------------- >>

            case WINDOW_BUFFER_SIZE_EVENT: {
                updateFrame(UPDATE_PARAMS);
                break;
            }
        }

        // Exit Condition

        if (nav.shouldExit()) {
            running = false;
        }
    }
}


// ----------------------------------------------------------------------------------------------------
// Helper Function
// ----------------------------------------------------------------------------------------------------

void updateFrame(
    Layout& lyt, 
    Navigation& nav, 
    Registry& registry,
    State& state, 
    Renderer& rdr
) {
    // Get Terminal Size

    int termW, termH;
    console::getTermSize(termW, termH);

    // Resolve Current Page

    auto currentPage = nav.current().page;
    const auto &page = registry.getPage(currentPage);
    const auto &items = page.options;
    const auto &ctx = page.context;

    // Count BODY Items

    int bodyCount = 0;
    for (const auto &item : items) {
        if (item.placement == Options::Placement::BODY) {
            bodyCount++;
        }
    }

    // Compute Layout

    auto geo = lyt.compute(termW, termH, bodyCount);

    // Render Frame

    std::string breadCrumb = nav.breadCrumb();
    rdr.render(geo, state, items, nav, ctx);
}