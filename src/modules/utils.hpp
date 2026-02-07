#pragma once

namespace console {
    void getTerminalSize(int &width, int &height);
    void clearScreen();
    void moveCursor(int x, int y);
}