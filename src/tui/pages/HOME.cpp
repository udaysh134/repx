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
    "Welcome to RepX! If you're starting for the first time, create a new file and proceed or open your existing file to manage your data."
};


// ----------------------------------------------------------------------------------------------------
// Options
// ----------------------------------------------------------------------------------------------------

static std::vector<Options::Item> options = {
    {
        "Create New",
        OptionId::HOME_CREATE_NEW,
        type::ACTION,
        placement::BODY,
        targetPage::NEW
    },
    {
        "Open Existing",
        OptionId::HOME_OPEN_EXISTING,
        type::ACTION,
        placement::BODY,
        targetPage::OPEN
    },
    {
        "Settings",
        OptionId::HOME_SETTINGS,
        type::ACTION,
        placement::BODY,
        targetPage::SETTINGS
    },
    {
        "Exit",
        OptionId::HOME_EXIT,
        type::ACTION,
        placement::BODY,
        targetPage::EXIT
    }
};


// ----------------------------------------------------------------------------------------------------
// Page Configuration
// ----------------------------------------------------------------------------------------------------

static PageConfig page {
    Page::HOME,
    context,
    options
};


// ----------------------------------------------------------------------------------------------------
// Page Registration
// ----------------------------------------------------------------------------------------------------

static Registrar reg(page);