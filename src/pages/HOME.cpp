#include "navigation.hpp"
#include "registry.hpp"

using PageContext = Navigation::PageContext;

PageContext home_Context() {
    return {
        "home",
        "RepX",
        ""
    };
}

static bool registered = [](){
    Registry::registerPage(PageId::HOME, home_Context);
    
    return true;
}();