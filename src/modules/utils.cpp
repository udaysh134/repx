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


/*
----------------------------------------------------------------------------------------------------
RENDERER'S DRAW FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
namespace draw {
    void horzLine(int x, int y, int width) {
        console::mvCursor(x, y);
        for (int i = 0; i < width; i++) {
            std::cout << cfg.screen.border.horz;
        }
    }

    void vertLine(int x, int y, int height) {
        for (int i = 0; i < height; i++) {
            console::mvCursor(x, y + i);
            std::cout << cfg.screen.border.vert;
        }
    }

    /**
     * - x : cursor on x-axis
     * - y : cursor on y-axis
     * - w : width of the region
     * - h : height of the region
     */
    void drawBox(int x, int y, int w, int h) {
        // Top & Bottom
        horzLine(x + 1, y, w - 2);
        horzLine(x + 1, y + h - 1, w - 2);

        // Left & Right
        vertLine(x, y + 1, h - 2);
        vertLine(x + w - 1, y + 1, h - 2);

        // Corners
        console::mvCursor(x, y);
        std::cout << cfg.screen.border.corner.rounded.tl;
        console::mvCursor(x + w - 1, y);
        std::cout << cfg.screen.border.corner.rounded.tr;
        console::mvCursor(x, y + h - 1);
        std::cout << cfg.screen.border.corner.rounded.bl;
        console::mvCursor(x + w - 1, y + h - 1);
        std::cout << cfg.screen.border.corner.rounded.br;
    }
}