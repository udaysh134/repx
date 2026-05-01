/**
 * @file SETTINGS.cpp
 * @brief Page module for SETTINGS navigation page.
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
    "settings",
    ""
};


// ----------------------------------------------------------------------------------------------------
// Options
// ----------------------------------------------------------------------------------------------------

static std::vector<Options::Item> options = {
    {
        "Sharp Borders",
        OptionId::SETTINGS_SHARP_BORDERS,
        type::SELECTION,
        placement::BODY
    },
    {
        "Cursor as Box",
        OptionId::SETTINGS_CURSOR_AS_BOX,
        type::SELECTION,
        placement::BODY
    },
    {
        "Dynamic Resize",
        OptionId::SETTINGS_DYNAMIC_RESIZE,
        type::SELECTION,
        placement::BODY
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
    Page::SETTINGS,
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