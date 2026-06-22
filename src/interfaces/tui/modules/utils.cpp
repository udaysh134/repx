// Headers
#include <iostream>
#include <string>
#include <windows.h>

#include "settings.hpp"


// ----------------------------------------------------------------------------------------------------
// Console Utility
// ----------------------------------------------------------------------------------------------------

namespace console {
    // Clear Screen ---------------------------------------- >>
    
    void clrScreen() {
        system("cls");
    }

    // Get Terminal Size ---------------------------------------- >>

    void getTermSize(int &width, int &height) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(hConsole, &csbi);

        width  = csbi.srWindow.Right  - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top  + 1;
    }

    // Move Cursor ---------------------------------------- >>

    void mvCursor(int x, int y) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD pos;
        pos.X = static_cast<SHORT>(x);
        pos.Y = static_cast<SHORT>(y);

        SetConsoleCursorPosition(hConsole, pos);
    }

    // Show Cursor ---------------------------------------- >>

    void showCursor(bool choice) {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;

        GetConsoleCursorInfo(hOut, &cursorInfo);
        cursorInfo.bVisible = choice;
        SetConsoleCursorInfo(hOut, &cursorInfo);
    }
}


// ----------------------------------------------------------------------------------------------------
// Text Aligning Utility
// ----------------------------------------------------------------------------------------------------

namespace alignText {
    // For Center ---------------------------------------- >>

    int center(int width, std::string str) {
        return (width - str.length()) / 2;
    }
}