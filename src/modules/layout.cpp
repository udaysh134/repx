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
}