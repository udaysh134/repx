// Headers
#include <iostream>
#include <conio.h>

#include "settings.hpp"
#include "utils.hpp"
#include "layout.hpp"
#include "navigation.hpp"
#include "options.hpp"
#include "state.hpp"
#include "renderer.hpp"


// ----------------------------------------------------------------------------------------------------
// Engine Main Loop
// ----------------------------------------------------------------------------------------------------

void start() {
    Layout layout;
    Renderer renderer;
    Navigation navigation;
    Options optionsManager;
    State state;

    bool running = true;

    while (running) {
        // Get Terminal Size ---------------------------------------- >>

        int termW;
        int termH;
        console::getTermSize(termW, termH);

        // Resolve Current Page ---------------------------------------- >>

        auto currentPage = navigation.current().page;
        const auto& items = optionsManager.get(currentPage);

        // Count BODY Items ---------------------------------------- >>

        int bodyCount = 0;
        for (const auto& item : items) {
            if (item.placement == Options::Placement::BODY) {
                bodyCount++;
            }
        }

        // Compute Layout ---------------------------------------- >>

        auto geo = layout.compute(termW, termH, bodyCount);

        // Render Frame ---------------------------------------- >>

        renderer.render(geo, state, items);

        // Input Handling ---------------------------------------- >>

        int key = _getch();

        switch (key) {
            case 72 : { // Up Arrow
                state.moveUp(items.size());
                break;
            }

            case 80 : { // Down Arrow
                state.moveDown(items.size());
                break;
            }

            case 13 : { // Enter
                if (items.empty()) break;

                const auto& selected = items[state.index()];

                if (selected.type == Options::Type::ACTION) {
                    navigation.enter(selected.targetPage, {});
                    state.reset();
                } else if (selected.type == Options::Type::INPUT) {
                    state.startEditing();
                } else if (selected.type == Options::Type::SELECTION) {
                    state.toggleSelection(state.index());
                }

                break;
            }

            case 27 : { // ESC
                if (navigation.canGoBack()) {
                    navigation.back();
                    state.reset();
                } else {
                    running = false;
                }

                break;
            }

            default: {
                if (state.isEditing()) {
                    if (key == 8) { // Backspace
                        state.removeChar();
                    } else {
                        state.appendChar(static_cast<char>(key));
                    }
                }

                break;
            }
        }

        // Exit Condition ---------------------------------------- >>

        if (navigation.shouldExit()) {
            running = false;
        }
    }
}