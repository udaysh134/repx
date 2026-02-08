#pragma once

namespace draw {
    void horizontalLine(int x, int y, int width, char ch);
    void verticalLine(int x, int y, int height, char ch);
    void drawBox(int x, int y, int w, int h, char h_char, char v_char, char c_char);
}