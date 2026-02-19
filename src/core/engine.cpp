// Headers
#include <iostream>
#include <string>
#include <conio.h>

#include "settings.hpp"
#include "utils.hpp"
#include "layout.hpp"


/*
----------------------------------------------------------------------------------------------------
MAIN CHECK & LOOP
----------------------------------------------------------------------------------------------------
*/
void start() {
    int scrnWidth, scrnHeight;

    int min_W = cfg.screen.min_W;
    int min_H = cfg.screen.min_H;

    std::string errLine_1 = "Error : Terminal too small";
    std::string errLine_2 = "Minimum required screen size : " + std::to_string(min_W) + " x " + std::to_string(min_H);

    console::getTermSize(scrnWidth, scrnHeight);

    if (scrnWidth < min_W || scrnHeight < min_H) {
        console::clrScreen();

        int centerY = scrnHeight / 2;
        int err1X = (scrnWidth - errLine_1.length()) / 2;
        int err2X = (scrnWidth - errLine_2.length()) / 2;

        console::mvCursor(err1X, centerY - 1);
        std::cout << color::RED << errLine_1 << color::RESET;

        console::mvCursor(err2X, centerY);
        std::cout << color::BLUE << errLine_2 << color::RESET;
    }


    int boxHeight_H = cfg.screen.layout.height.h;
    int boxHeight_F = cfg.screen.layout.height.f;
    int boxHeight_B = scrnHeight - boxHeight_H - boxHeight_F;

    draw::drawBox(0, 0, scrnWidth, boxHeight_H);
    draw::drawBox(0, boxHeight_H, scrnWidth, boxHeight_B);
    draw::drawBox(0, boxHeight_H + boxHeight_B, scrnWidth, boxHeight_F);

    std::string title = std::string(cfg.program.name) + " " + std::string(cfg.program.version);
    console::mvCursor(alignTxt::center(scrnWidth, title), 2);
    std::cout << title;

    getch();

    bool  running = true;
    while (running) {
        
    }
}