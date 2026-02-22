// Headers
#include <windows.h>

#include "engine.hpp"
#include "utils.hpp"


/*
----------------------------------------------------------------------------------------------------
INITIALIZATION
----------------------------------------------------------------------------------------------------
*/
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    console::showCursor(FALSE);

    start();

    console::clrScreen();
    console::showCursor(TRUE);
    
    return 0;
}