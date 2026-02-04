#include <curses.h>

#include "exit_menu.hpp"
#include "../app_state.hpp"

AppState runExitMenu() {
    getch();
    return AppState::EXIT_MENU;
}