/**
 * @file NEW.cpp
 * @brief Page module for NEW navigation page.
 */

// Headers
#include "registry.hpp"
#include "navigation.hpp"
#include "options.hpp"
#include "state.hpp"

#include "repEngine.hpp"
#include <string>
#include <iostream>

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
    "new",
    ""
};


// ----------------------------------------------------------------------------------------------------
// Options
// ----------------------------------------------------------------------------------------------------

static std::vector<Options::Item> options = {
    {
        "Select Directory",
        OptionId::NEW_SELECT_DIRECTORY,
        type::ACTION,
        placement::BODY
    },
    {
        "Folder Path",
        OptionId::NEW_FOLDER_PATH,
        type::INPUT,
        placement::FOOTER
    }
};


// ----------------------------------------------------------------------------------------------------
// Logic
// ----------------------------------------------------------------------------------------------------

// On Enter ---------------------------------------- >>

static void onEnter(Navigation& nav, State& state) {}

// On Action ---------------------------------------- >>

static void onAction(Navigation& nav, State& state, const Options::Item& item) {
    if(item.id == OptionId::NEW_SELECT_DIRECTORY) {
        std::string path = RepEngine::select_directory();

        if(path == "") {
            system("cls");        
            std::cout << "Error : You didn't select anything";
            exit(0);
        } else {
            system("cls");
            std::cout << "Verifying!";
            std::cout << path;
            exit(0);
        }
    }
}

// On Input ---------------------------------------- >>

static void onInput(Navigation& nav, State& state, int key) {}


// ----------------------------------------------------------------------------------------------------
// Helper Functions
// ----------------------------------------------------------------------------------------------------




// ----------------------------------------------------------------------------------------------------
// Page Configuration
// ----------------------------------------------------------------------------------------------------

static PageConfig page {
    Page::NEW,
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