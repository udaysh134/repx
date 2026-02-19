// Headers
#include "navigation.hpp"


/*
----------------------------------------------------------------------------------------------------
Constructor Definition
----------------------------------------------------------------------------------------------------
*/
Navigation::Navigation() {
    lineUp.push_back({ PageId::HOME, { "Home/", "", "" }});
}


/*
----------------------------------------------------------------------------------------------------
Member Function Definitions
----------------------------------------------------------------------------------------------------
*/
void Navigation::enter(PageId page, PageContext context) {
    lineUp.push_back({ page, context });
}

void Navigation::back() {
    if (lineUp.size() > 1) {
        lineUp.pop_back();
    }
}

const Navigation::NavNode& Navigation::current() const {
    return lineUp.back();
}

bool Navigation::canGoBack() const {
    return lineUp.size() > 1;
}

bool Navigation::shouldExit() const {
    return current().page == PageId::EXIT;
}