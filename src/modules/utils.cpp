// Headers
#include <iostream>
#include <windows.h>
#include <string>

#include "layout.hpp"


/*
----------------------------------------------------------------------------------------------------
CONSOLE FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
namespace console {
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

    void clrScr() {
        system("cls");
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
     * - y : the line at which this text goes
     */
    int center(int w, std::string str) { return (w - str.length()) / 2; }
}