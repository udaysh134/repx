// Headers
#include <curses.h>

#include "../screen.hpp"
#include "main_menu.hpp"

// Constants
static const char* ITEMS[] = { "New", "Open", "Exit" };
static const int ITEM_COUNT = 3;


/*
----------------------------------------------------------------------------------------------------
MAIN MENU
----------------------------------------------------------------------------------------------------
*/
Screen runMainMenu() {
    int selected = 0;

    while (true) {
        clear();

        mvprintw(2, 4, "RepX");

        for (int i = 0; i < ITEM_COUNT; i++) {
            if (i == selected) {
                attron(A_REVERSE);
            }

            mvprintw(5 + i, 6, ITEMS[i]);

            if (i == selected) {
                attroff(A_REVERSE);
            }
        }

        refresh();

        int ch = getch();

        switch (ch) {
            case KEY_UP:
                selected = (selected - 1 + ITEM_COUNT) % ITEM_COUNT;
                break;

            case KEY_DOWN:
                selected = (selected + 1) % ITEM_COUNT;
                break;

            case '\n':
                if (selected == 0) return Screen::NEW_MENU;
                if (selected == 1) return Screen::OPEN_MENU;
                if (selected == 2) return Screen::EXIT_MENU;
                break;
        }
    }
}