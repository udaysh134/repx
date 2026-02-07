// Headers
#include <iostream>
#include <windows.h>


/*
----------------------------------------------------------------------------------------------------
CONSOLE FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
namespace console {
    // ------=>> | GET TERMINAL SIZE | <<=------
    /**
     * - Create variables
     * - Pass variables as arguments : width, height
     * - Get width and height of the screen directly 
     */
    void getTerminalSize(int &width, int &height) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(hConsole, &csbi);

        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }


    // ------=>> | CLEAR SCREEN | <<=------
    void clearScreen() {

    }


    // ------=>> | MOVE CURSOR | <<=------
    /**
     * - Directly pass the position where cursor is needed
     */
    void moveCursor(int x, int y) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD pos;
        pos.X = static_cast<SHORT>(x);
        pos.Y = static_cast<SHORT>(y);

        SetConsoleCursorPosition(hConsole, pos);
    }
}