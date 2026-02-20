// Headers
#include <iostream>
#include <conio.h>

#include "settings.hpp"
#include "utils.hpp"
#include "layout.hpp"
#include "renderer.hpp"
#include "navigation.hpp"
#include "options.hpp"
#include "state.hpp"


/*
----------------------------------------------------------------------------------------------------
Main Running
----------------------------------------------------------------------------------------------------
*/
void start() {
    Layout layout;
    Renderer renderer;
    Navigation navigation;
    Options optionsManager;
    State state;

    bool running = true;

    while (running) {
        // 1. Get Terminal Size
        int termW, termH;
        console::getTermSize(termW, termH);

        // 2. Get Current Page
        auto currentPage = navigation.current().page;

        // 3. Get Options for Current Page
        const auto& items = optionsManager.get(currentPage);

        // 4. Count BODY items (for layout spacing)
        int bodyCount = 0;
        for (const auto& item : items) { if (item.placement == Options::Placement::BODY) bodyCount++; }

        // 5. Compute Layout Geometry
        auto geo = layout.compute(termW, termH, bodyCount);

        // 6. Render Everything
        renderer.render(geo, state, items);

        // 7. Input Handling (Test Phase Basic)
        int key = _getch();

        switch (key) {
            case 72: { // Up Arrow
                state.moveUp(items.size());
                break;
            }

            case 80: { // Down Arrow
                state.moveDown(items.size());
                break;
            }

            case 13: { // Enter
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
            
            case 27: { // ESC
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

        // Exit condition
        if (navigation.shouldExit()) running = false;
    }
}