#include "navigation.hpp"
#include "registry.hpp"

static PageContext HOME_context() {
    return {
        "home",
        "",
        ""
    };
}

static void HOME_onEnter(Navigation& nav, State& state) {
    state.reset();
}

static bool registered = []() {
    Registry::registerPage(
        PageId::HOME, 
        {
            HOME_context,
            HOME_onEnter,
            nullptr,
            nullptr
        }
    );

    return true;
}();