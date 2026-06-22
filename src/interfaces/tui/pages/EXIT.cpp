/**
 * @file EXIT.cpp
 * @brief Page module for EXIT navigation page.
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
    "exit",
    ""
};


// ----------------------------------------------------------------------------------------------------
// Options
// ----------------------------------------------------------------------------------------------------

static std::vector<Options::Item> options = {
    {
        "Yes",
        OptionId::EXIT_YES,
        type::ACTION,
        placement::FOOTER
    },
    {
        "Cancel",
        OptionId::EXIT_CANCEL,
        type::ACTION,
        placement::FOOTER
    }
};


// ----------------------------------------------------------------------------------------------------
// Logic
// ----------------------------------------------------------------------------------------------------

// On Enter ---------------------------------------- >>

static void onEnter(Navigation& nav, State& state) {}

// On Action ---------------------------------------- >>

static void onAction(Navigation& nav, State& state, const Options::Item& item) {}

// On Input ---------------------------------------- >>

static void onInput(Navigation& nav, State& state, int key) {}


// ----------------------------------------------------------------------------------------------------
// Helper Functions
// ----------------------------------------------------------------------------------------------------




// ----------------------------------------------------------------------------------------------------
// Page Configuration
// ----------------------------------------------------------------------------------------------------

static PageConfig page {
    Page::EXIT,
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