// Headers
#include <iostream>
#include "utils.hpp"


/*
----------------------------------------------------------------------------------------------------
MAIN LOOP
----------------------------------------------------------------------------------------------------
*/
void start() {
    int width, height;

    console::getTerminalSize(width, height);

    int headerH = 5;
    int footerH = 5;
    int bodyH = height - headerH - footerH;

    char h_char = '-';
    char v_char = '|';
    char c_char = '+';

    // Header Box
    console::drawBox(0, 0, width, headerH, h_char, v_char,c_char);
    // Body Box
    console::drawBox(0, headerH, width, bodyH, h_char, v_char,c_char);
    // Footer Box
    console::drawBox(0, headerH + bodyH, width, footerH, h_char, v_char,c_char);

    std::string title = "RepX v0.0.0";
    int titleX = (width - title.length()) / 2;
    int titleY = 2;

    console::moveCursor(titleX, titleY);
    std::cout << title;

    bool  running = true;
    while (running) {
        
    }
}