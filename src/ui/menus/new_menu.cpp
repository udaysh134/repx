#include <curses.h>

#include "new_menu.hpp"
#include "../app_state.hpp"

AppState runNewMenu() {
    getch();
    return AppState::NEW_MENU;
}