/**
 * @file utils.hpp
 * @brief Utility file for reusable functions.
 *
 * Provides three section of utilities.
 * "color", "console" and "alignText" for respective usage.
 */

#pragma once

#include <string>


// ----------------------------------------------------------------------------------------------------
// Utility 1
// ----------------------------------------------------------------------------------------------------

/**
 * @brief ANSI color escape sequences.
 * 
 * Requires terminal support for ANSI codes.
 * Always use RESET after applying a color.
 */
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


// ----------------------------------------------------------------------------------------------------
// Utility 2
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Low-level console utilities.
 * 
 * Windows-only implementations using WinAPI.
 * Provides screen clearing, cursor control, and terminal sizing.
 */
namespace console {
    /** 
     * Clears the console screen.
     * Uses Windows API's system("cls").
     */
    void clrScreen();

    /**
     * Retrieves visible (not full buffer) console window dimensions.
     * 
     * @param[out] width Receives column count.
     * @param[out] height Receives row count.
     */
    void getTermSize(int &width, int &height);

    /**
     * Moves cursor to (x, y).
     * 
     * @param[in] x Position of X-Coordinate in integer.
     * @param[in] y Position of Y-Coordinate in integer.
     */
    void mvCursor(int x, int y);

    /**
     * Shows or hides the console cursor.
     * 
     * @param[in] choice TRUE to show, FALSE to hide cursor.
     */
    void showCursor(bool choice);
}


// ----------------------------------------------------------------------------------------------------
// Utility 3
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Text alignment utilities for the visible console area.
 * 
 * Provides helper functions for positioning text.
 * Works within the terminal layout.
 */
namespace alignText {
    /**
     * Returns horizontal center position for a string.
     * 
     * @param[in] width Total available width.
     * @param[in] str Text which is to be centered.
     * 
     * @return Starting X-Coordinate as integer.
     */
    int center(int width, std::string str);
}