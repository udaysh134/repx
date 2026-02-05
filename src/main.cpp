// Headers
#include <curses.h>

#include "ui/app.hpp"


/*
----------------------------------------------------------------------------------------------------
INITIALIZATION
----------------------------------------------------------------------------------------------------
*/
int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    runApp();

    endwin();   
    return 0;
}