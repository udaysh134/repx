// Headers
#include <curses.h>

#include "../screen.hpp"
#include "exit_menu.hpp"


/*
----------------------------------------------------------------------------------------------------
EXIT MENU
----------------------------------------------------------------------------------------------------
*/
Screen runExitMenu() {
    getch();
    return Screen::EXIT_MENU;
}