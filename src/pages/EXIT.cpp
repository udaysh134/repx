#include "navigation.hpp"
#include "registry.hpp"

using PageContext = Navigation::PageContext;

PageContext exit_Context() {
    return {
        "exit",
        "",
        ""
    };
}

static bool registered = [](){
    Registry::registerPage(PageId::EXIT, exit_Context);
    
    return true;
}();