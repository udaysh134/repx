// Headers
#include <iostream>
#include "../modules/utils.hpp"


/*
----------------------------------------------------------------------------------------------------
MAIN LOOP
----------------------------------------------------------------------------------------------------
*/
void start() {
    int width, height;

    console::getTerminalSize(width, height);

    console::moveCursor(0, 0);
    std::cout << "Terminal size: " << width << " x " << height << "\n";

    console::moveCursor(0, 2);
    std::cout << "Hello from RepX";

    while (true) {
        
    }
}