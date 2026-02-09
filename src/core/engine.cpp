// Headers
#include <iostream>
#include <string>
#include <conio.h>

#include "utils.hpp"
#include "layout.hpp"

// Constants
constexpr int MIN_SCR_WIDTH  = 60;
constexpr int MIN_SCR_HEIGHT = 20;


/*
----------------------------------------------------------------------------------------------------
MAIN LOOP
----------------------------------------------------------------------------------------------------
*/
void start() {
    int width, height;
    console::getTerminalSize(width, height);

    if (width < MIN_SCR_WIDTH || height < MIN_SCR_HEIGHT) {
        std::string errLine_1 = "Error : Terminal too small";
        std::string errLine_2 = "Minimum required screen resolution : " + std::to_string(MIN_SCR_WIDTH) + " x " + std::to_string(MIN_SCR_HEIGHT);

        console::clearScreen();

        int centerY = height / 2;
        int err1X = (width - errLine_1.length()) / 2;
        int err2X = (width - errLine_2.length()) / 2;

        console::moveCursor(err1X, centerY - 1);
        std::cout << color::RED << errLine_1 << color::RESET;

        console::moveCursor(err2X, centerY);
        std::cout << color::BLUE << errLine_2 << color::RESET;
    }

    int headerH = 5;
    int footerH = 5;
    int bodyH = height - headerH - footerH;

    char h_char = '-';
    char v_char = '|';
    char c_char = '+';

    // Header Box
    draw::drawBox(0, 0, width, headerH, h_char, v_char,c_char);
    // Body Box
    draw::drawBox(0, headerH, width, bodyH, h_char, v_char,c_char);
    // Footer Box
    draw::drawBox(0, headerH + bodyH, width, footerH, h_char, v_char,c_char);

    std::string title = "RepX v0.0.0";
    int titleX = (width - title.length()) / 2;
    int titleY = 2;

    console::moveCursor(titleX, titleY);
    std::cout << title;

    getch();

    bool  running = true;
    while (running) {
        
    }
}