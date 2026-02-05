// Headers
#include "app.hpp"
#include "screen.hpp"

#include "menus/main_menu.hpp"
#include "menus/new_menu.hpp"
#include "menus/open_menu.hpp"
#include "menus/exit_menu.hpp"


/*
----------------------------------------------------------------------------------------------------
PROGRAM RUN
----------------------------------------------------------------------------------------------------
*/
void runApp() {
    Screen state = Screen::MAIN_MENU;

    while (state != Screen::EXIT_MENU) {
        switch (state) {
            case Screen::MAIN_MENU:
                state = runMainMenu();
                break;

            case Screen::NEW_MENU:
                state = runNewMenu();
                break;

            case Screen::OPEN_MENU:
                state = runOpenMenu();
                break;

            case Screen::EXIT_MENU:
                break;
        }
    }
}