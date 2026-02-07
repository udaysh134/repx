#pragma once

namespace console {
    void getTerminalSize(int &width, int &height);
    void clearScreen();
    void moveCursor(int x, int y);
    void drawBox(int x, int y, int w, int h, char h_char, char v_char, char c_char);
}