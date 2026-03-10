#include "navigation.hpp"
#include "registry.hpp"

using PageContext = Navigation::PageContext;

PageContext settings_Context() {
    return {
        "settings",
        "",
        ""
    };
}

static bool registered = [](){
    Registry::registerPage(PageId::SETTINGS, settings_Context);
    
    return true;
}();