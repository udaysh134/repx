/**
 * @file main.cpp
 * @brief Entry point for RepX.
 *
 * Sets up UTF-8 console mode and boots the engine.
 * Works as the initializer for the program.
 */

// Headers
#include <windows.h>

#include "engine.hpp"
#include "utils.hpp"


// ----------------------------------------------------------------------------------------------------
// Main Entry Point
// ----------------------------------------------------------------------------------------------------

int main() {
    // Enable UTF-8 for proper Unicode border rendering.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Hide cursor during TUI runtime.
    console::showCursor(FALSE);

    start();// Start engine

    // Restore console state before exit.
    console::clrScreen();
    console::showCursor(TRUE);

    return 0;
}