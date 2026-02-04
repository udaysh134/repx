#include <curses.h>

#include "main_menu.hpp"
#include "../app_state.hpp"

AppState runMainMenu() {
    getch();
    return AppState::MAIN_MENU;
}