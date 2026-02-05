// Headers
#include <curses.h>

#include "open_menu.hpp"
#include "../screen.hpp"


/*
----------------------------------------------------------------------------------------------------
OPEN MENU
----------------------------------------------------------------------------------------------------
*/
Screen runOpenMenu() {
    getch();
    return Screen::OPEN_MENU;
}