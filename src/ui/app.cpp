#include "app.hpp"
#include "app_state.hpp"

#include "menus/main_menu.hpp"
#include "menus/new_menu.hpp"
#include "menus/open_menu.hpp"
#include "menus/exit_menu.hpp"


void runApp() {
    AppState state = AppState::MAIN_MENU;

    while (state != AppState::EXIT_MENU) {
        switch (state) {
            case AppState::MAIN_MENU:
                state = runMainMenu();
                break;

            case AppState::NEW_MENU:
                state = runNewMenu();
                break;

            case AppState::OPEN_MENU:
                state = runOpenMenu();
                break;

            case AppState::EXIT_MENU:
                break;
        }
    }
}