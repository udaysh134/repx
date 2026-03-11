// Headers
#include "registry.hpp"
#include "navigation.hpp"
#include "options.hpp"

// Definitions
using type = Options::Type;
using placement = Options::Placement;
using targetPage = Navigation::PageId;
using PageConfig = Registry::PageConfig;
using Page = Navigation::PageId;
using Registrar = Registry::PageRegistrar;


// ----------------------------------------------------------------------------------------------------
// Context
// ----------------------------------------------------------------------------------------------------

static Navigation::PageContext ctx {
    "home",
    ""
};


// ----------------------------------------------------------------------------------------------------
// Options
// ----------------------------------------------------------------------------------------------------

static std::vector<Options::Item> opt = {
    { "Create New", type::ACTION, placement::BODY, targetPage::NEW },
    { "Open Existing", type::ACTION, placement::BODY, targetPage::OPEN },
    { "Settings", type::ACTION, placement::BODY, targetPage::SETTINGS },
    { "Exit", type::ACTION, placement::BODY, targetPage::EXIT },
};


// ----------------------------------------------------------------------------------------------------
// Logic
// ----------------------------------------------------------------------------------------------------

static void onEnter(Navigation& nav, State& state) {
    // Optional page initialization logic
}

static void onAction(Navigation& nav, State& state, const Options::Item& item) {
    // Optional action logic after pressing ENTER on an ACTION item
}

static void onInput(Navigation& nav, State& state, int key) {
    // Optional key handling specific to this page
}


// ----------------------------------------------------------------------------------------------------
// Configuration
// ----------------------------------------------------------------------------------------------------

static PageConfig page {
    Page::HOME,
    ctx,
    opt,
    onEnter,
    onAction,
    onInput
};


// ----------------------------------------------------------------------------------------------------
// Registration
// ----------------------------------------------------------------------------------------------------

static Registrar reg(page);