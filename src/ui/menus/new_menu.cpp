// Headers
#include <curses.h>

#include "../screen.hpp"
#include "new_menu.hpp"


/*
----------------------------------------------------------------------------------------------------
NEW MENU
----------------------------------------------------------------------------------------------------
*/
Screen runNewMenu() {
    getch();
    return Screen::NEW_MENU;
}