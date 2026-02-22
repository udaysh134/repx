// Headers
#include <iostream>
#include <string>
#include <windows.h>

#include "settings.hpp"


/*
----------------------------------------------------------------------------------------------------
CONSOLE FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
namespace console {
    void clrScreen() {
        system("cls");
    }

    /**
     * - width : local variable to store fetched width
     * - height : local variable to store fetched height
     */
    void getTermSize(int &width, int &height) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(hConsole, &csbi);

        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }

    /**
     * - x : cursor on x-axis
     * - y : cursor on y-axis
     */
    void mvCursor(int x, int y) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD pos;
        pos.X = static_cast<SHORT>(x);
        pos.Y = static_cast<SHORT>(y);

        SetConsoleCursorPosition(hConsole, pos);
    }

    void showCursor(bool choice) {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;

        GetConsoleCursorInfo(hOut, &cursorInfo);
        cursorInfo.bVisible = choice;
        SetConsoleCursorInfo(hOut, &cursorInfo);
    }
}


/*
----------------------------------------------------------------------------------------------------
TEXT ALIGN FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
namespace alignTxt {
    /**
     * - w : width of the current screen
     * - str : the text being put on the screen
     */
    int center(int w, std::string str) { return (w - str.length()) / 2; }
}