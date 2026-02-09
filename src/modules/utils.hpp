#pragma once

namespace console {
    void getTerminalSize(int &width, int &height);
    void clearScreen();
    void moveCursor(int x, int y);
}


namespace color {
    inline constexpr const char* BLACK = "\033[0;30m";
    inline constexpr const char* RED = "\033[0;31m";
    inline constexpr const char* GREEN = "\033[0;32m";
    inline constexpr const char* YELLOW = "\033[0;33m";
    inline constexpr const char* BLUE = "\033[0;34m";
    inline constexpr const char* MAGENTA = "\033[0;35m";
    inline constexpr const char* CYAN = "\033[0;36m";
    inline constexpr const char* WHITE = "\033[0;37m";
    inline constexpr const char* RESET = "\033[0m";
}