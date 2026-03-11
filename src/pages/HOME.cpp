/**
 * @file HOME.cpp
 * @brief Page module for HOME navigation page.
 */

// Headers
#include "registry.hpp"
#include "navigation.hpp"
#include "options.hpp"
#include "state.hpp"

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

static Navigation::PageContext context {
    "home",
    ""
};


// ----------------------------------------------------------------------------------------------------
// Options
// ----------------------------------------------------------------------------------------------------

static std::vector<Options::Item> options = {
    { "Create New", type::ACTION, placement::BODY, targetPage::NEW },
    { "Open Existing", type::ACTION, placement::BODY, targetPage::OPEN },
    { "Settings", type::ACTION, placement::BODY, targetPage::SETTINGS },
    { "Exit", type::ACTION, placement::BODY, targetPage::EXIT },
};


// ----------------------------------------------------------------------------------------------------
// Logic
// ----------------------------------------------------------------------------------------------------

// On Enter ---------------------------------------- >>

static void onEnter(Navigation& nav, State& state) {
    // Optional page initialization logic
}

// On Action ---------------------------------------- >>

static void onAction(Navigation& nav, State& state, const Options::Item& item) {
    // Optional action logic after pressing ENTER on an ACTION item
}

// On Input ---------------------------------------- >>

static void onInput(Navigation& nav, State& state, int key) {
    // Optional key handling specific to this page
}


// ----------------------------------------------------------------------------------------------------
// Helper Functions (Optional)
// ----------------------------------------------------------------------------------------------------




// ----------------------------------------------------------------------------------------------------
// Page Configuration
// ----------------------------------------------------------------------------------------------------

static PageConfig page {
    Page::HOME,
    context,
    options,
    onEnter,
    onAction,
    onInput
};


// ----------------------------------------------------------------------------------------------------
// Page Registration
// ----------------------------------------------------------------------------------------------------

static Registrar reg(page);