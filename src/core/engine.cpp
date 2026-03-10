// Headers
#include <iostream>
#include <windows.h>

#include "engine.hpp"
#include "settings.hpp"
#include "utils.hpp"
#include "pageReg.hpp"

#include "layout.hpp"
#include "navigation.hpp"
#include "options.hpp"
#include "state.hpp"
#include "renderer.hpp"

// Constants
#define UPDATE_PARAMS lyt, nav, opt, state, rdr


// ----------------------------------------------------------------------------------------------------
// Engine Main Loop
// ----------------------------------------------------------------------------------------------------

void start() {
    Layout lyt;
    Navigation nav;
    Options opt;
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
                const auto &items = opt.get(currentPage);

                switch (key) {
                    case VK_UP : { // Up Arrow
                        if (items.empty()) break;
                        
                        state.moveUp(items.size());
                        updateFrame(UPDATE_PARAMS);
                        break;
                    }

                    case VK_DOWN : { // Down Arrow
                        if (items.empty()) break;

                        state.moveDown(items.size());
                        updateFrame(UPDATE_PARAMS);
                        break;
                    }

                    case VK_RETURN : { // Enter
                        if (items.empty()) break;
                        if (state.index() >= items.size()) state.reset();

                        const auto &selected = items[state.index()];

                        if (selected.type == Options::Type::ACTION) {
                            auto ctx = Registry::getContext(selected.targetPage);
                            nav.enter(selected.targetPage, ctx);
                            
                            state.reset();
                            updateFrame(UPDATE_PARAMS);
                        } else if (selected.type == Options::Type::INPUT) {
                            state.startEditing();
                            updateFrame(UPDATE_PARAMS);
                        } else if (selected.type == Options::Type::SELECTION) {
                            state.toggleSelection(state.index());
                            updateFrame(UPDATE_PARAMS);
                        }

                        break;
                    }

                    case VK_ESCAPE : { // ESC
                        if (items.empty()) break;

                        if (nav.canGoBack()) {
                            nav.back();
                            state.reset();
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
    Options& opt, 
    State& state, 
    Renderer& rdr
) {    
    // Get Terminal Size

    int termW, termH;
    console::getTermSize(termW, termH);

    // Resolve Current Page

    auto currentPage = nav.current().page;
    const auto &items = opt.get(currentPage);

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
    rdr.render(geo, state, items, breadCrumb);
}