#include <iostream>
using namespace std;

#include <curses.h>

#include <new.hpp>
#include <open.hpp>
#include <exit.hpp>


int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    mvprintw(1, 2, "RepX TUI booted.");
    mvprintw(3, 2, "Press any key to exit.");

    refresh();
    getch();

    endwin();
    return 0;


    // int input;

    // cout <<
    // "1. Create New" << endl << 
    // "2. Open Existing" << endl <<
    // "3. Exit";

    // cin >> input;

    // switch (input) {
    //     case 1:

    //         break;
    //     case 2:
        
    //         break;
    //     case 3:
        
    //         break;
    //     default:
    //         break;
    // }
}