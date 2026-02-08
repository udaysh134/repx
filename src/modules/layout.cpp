// Headers
#include <iostream>
#include "utils.hpp"


/*
----------------------------------------------------------------------------------------------------
UI LAYOUT FUNCTIONS
----------------------------------------------------------------------------------------------------
*/
namespace draw {
    void horizontalLine(int x, int y, int width, char ch) {
        console::moveCursor(x, y);
        for (int i = 0; i < width; i++) { std::cout << ch; }
    }


    void verticalLine(int x, int y, int height, char ch) {
        for (int i = 0; i < height; i++) {
            console::moveCursor(x, y + i);
            std::cout << ch;
        }
    }


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
        // Top & Bottom
        horizontalLine(x + 1, y, w - 2, h_char);
        horizontalLine(x + 1, y + h - 1, w - 2, h_char);

        // Left & Right
        verticalLine(x, y + 1, h - 2, v_char);
        verticalLine(x + w - 1, y + 1, h - 2, v_char);

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