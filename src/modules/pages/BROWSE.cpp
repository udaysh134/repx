#include "navigation.hpp"
#include "pageReg.hpp"

using PageContext = Navigation::PageContext;

PageContext browse_new_Context() {
    return {
        "new",
        "Create new",
        ""
    };
}

PageContext browse_open_Context() {
    return {
        "open",
        "Open existing",
        ""
    };
}

static bool registered = [](){
    Registry::registerPage(PageId::BROWSE, browse_new_Context);
    Registry::registerPage(PageId::OPEN, browse_open_Context);
    
    return true;
}();