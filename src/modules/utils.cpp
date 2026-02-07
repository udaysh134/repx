// Headers
#include <iostream>
#include <windows.h>
#include "layout.hpp"


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
        system("cls");
    }


    // ------=>> | MOVE CURSOR | <<=------
    /**
     * - Directly pass the position where cursor is needed
     * - 1st arg : cursor on x-axis
     * - 2nd arg : cursor on y-axis
     */
    void moveCursor(int x, int y) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD pos;
        pos.X = static_cast<SHORT>(x);
        pos.Y = static_cast<SHORT>(y);

        SetConsoleCursorPosition(hConsole, pos);
    }


    // ------=>> | DRAW THE BOX | <<=------
    /**
     * - x : cursor on x-axis
     * - y : cursor on y-axis
     * - w : width of the terminal
     * - h : height of the terminal
     * - h_char : character used for drawing horizontal line
     * - v_char : character used for drawing vertical line
     * - c_char : character used for corners
     */
    void drawBox(int x, int y, int w, int h, char h_char, char v_char, char c_char) {
        // Top
        draw::horizontalLine(x + 1, y, w - 2, h_char);
        // Bottom
        draw::horizontalLine(x + 1, y + h - 1, w - 2, h_char);

        // Left
        draw::verticalLine(x, y + 1, h - 2, v_char);
        // Right
        draw::verticalLine(x + w - 1, y + 1, h - 2, v_char);

        // Corners
        console::moveCursor(x, y);
        std::cout << c_char;
        console::moveCursor(x + w - 1, y);
        std::cout << c_char;
        console::moveCursor(x, y + h - 1);
        std::cout << c_char;
        console::moveCursor(x + w - 1, y + h - 1);
        std::cout << c_char;
    }
}