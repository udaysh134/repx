#include <curses.h>

#include "open_menu.hpp"
#include "../app_state.hpp"

AppState runOpenMenu() {
    getch();
    return AppState::OPEN_MENU;
}