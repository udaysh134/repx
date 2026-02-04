#include <curses.h>

#include "ui/app.hpp"
#include "ui/theme.hpp"


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