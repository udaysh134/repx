// Headers
#include "navigation.hpp"


// ----------------------------------------------------------------------------------------------------
// Constructor Definition
// ----------------------------------------------------------------------------------------------------

Navigation::Navigation() {
    stack.push_back({ PageId::HOME, { "Home/", "", "" } });
}


// ----------------------------------------------------------------------------------------------------
// Member Function Definitions
// ----------------------------------------------------------------------------------------------------

// Enter a specific Page ---------------------------------------- >>

void Navigation::enter(PageId page, PageContext context) {
    stack.push_back({ page, context });
}

// Go Back to the previous page ---------------------------------------- >>

void Navigation::back() {
    if (stack.size() > 1) {
        stack.pop_back();
    }
}

// Get Current Page ---------------------------------------- >>

const Navigation::NavNode& Navigation::current() const {
    return stack.back();
}

// Can Go Back ---------------------------------------- >>

bool Navigation::canGoBack() const {
    return stack.size() > 1;
}

// Should Exit ---------------------------------------- >>

bool Navigation::shouldExit() const {
    return current().page == PageId::EXIT;
}