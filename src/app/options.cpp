// Headers
#include "options.hpp"
#include "navigation.hpp"

// Declarations
using page = Navigation::PageId;
using type = Options::Type;
using placement = Options::Placement;
using target = Navigation::PageId;


/*
----------------------------------------------------------------------------------------------------
Constructor Definition
----------------------------------------------------------------------------------------------------
*/
Options::Options() {
    opt[page::HOME] = {
        { "Create New", type::ACTION, placement::BODY, target::BROWSE },
        { "Open Existing", type::ACTION, placement::BODY, target::BROWSE },
        { "Settings", type::ACTION, placement::BODY, target::SETTINGS },
        { "Exit", type::ACTION, placement::BODY, target::EXIT },
    };
    

    opt[page::BROWSE] = {
        { "Select File", type::ACTION, placement::BODY },
        { "Path", type::INPUT, placement::BODY },
    };


    opt[page::ERROR] = {
        { "Ok", type::ACTION, placement::BODY },
    };


    opt[page::SUCCESS] = {
        { "Ok", type::ACTION, placement::BODY },
    };


    opt[page::CONFIRMATION] = {
        { "Yes", type::ACTION, placement::BODY },
        { "No", type::ACTION, placement::BODY },
    };


    opt[page::NEW] = {
        { "Name", type::INPUT, placement::BODY },
        { "Description", type::INPUT, placement::BODY },
        { "Author", type::INPUT, placement::BODY },

        { "Save", type::ACTION, placement::FOOTER, target::HOME },
        { "Cancel", type::ACTION, placement::FOOTER, target::HOME },
    };


    opt[page::OPEN] = {
        { "View Entries", type::ACTION, placement::BODY, target::ENTRIES },
        { "Add an Entry", type::ACTION, placement::BODY, target::ENTRY_ADD },
        { "Generate Leaderboard", type::ACTION, placement::BODY, target::GEN_LB },
        { "?", type::ACTION, placement::BODY, target::CONSOLE_HELP },

        { "Console", type::INPUT, placement::FOOTER },
    };


    opt[page::ENTRIES] = {
        { "", type::TEXT, placement::BODY },
        { "Back", type::ACTION, placement::FOOTER, target::OPEN },
    };


    opt[page::ENTRY_ADD] = {
        { "Name", type::INPUT, placement::BODY },
        { "Increase", type::SELECTION, placement::BODY },
        { "Decrease", type::SELECTION, placement::BODY },
        { "Reason", type::INPUT, placement::BODY },

        { "Save", type::ACTION, placement::FOOTER, target::SUCCESS },
        { "Cancel", type::ACTION, placement::FOOTER, target::OPEN },
    };


    opt[page::GEN_LB] = {
        { "Weekly", type::ACTION, placement::BODY, target::GEN_LB_WEEKLY },
        { "Monthly", type::ACTION, placement::BODY, target::GEN_LB_MONTHLY },
        { "Yearly", type::ACTION, placement::BODY, target::GEN_LB_YEARLY },

        { "Custom", type::ACTION, placement::FOOTER, target::GEN_LB_CUSTOM },
    };


    opt[page::CONSOLE_HELP] = {
        { "", type::TEXT, placement::BODY },
        { "Back", type::ACTION, placement::FOOTER, target::OPEN },
    };


    opt[page::GEN_LB_WEEKLY] = {
        { "This Week", type::ACTION, placement::BODY },
        { "Last Week", type::ACTION, placement::BODY },
    };


    opt[page::GEN_LB_MONTHLY] = {
        { "This Month", type::ACTION, placement::BODY },
        { "Last Month", type::ACTION, placement::BODY },
    };


    opt[page::GEN_LB_YEARLY] = {
        { "This Year", type::ACTION, placement::BODY },
        { "Last Year", type::ACTION, placement::BODY },
    };


    opt[page::GEN_LB_CUSTOM] = {
        { "Start Date", type::INPUT, placement::BODY },
        { "End Date", type::INPUT, placement::BODY },

        { "Ok", type::ACTION, placement::FOOTER, target::SUCCESS },
        { "Cancel", type::ACTION, placement::FOOTER, target::GEN_LB },
    };


    opt[page::SETTINGS] = {
        { "Back", type::ACTION, placement::FOOTER, target::HOME },
    };


    opt[page::EXIT] = {
        { "Yes", type::ACTION, placement::BODY, target::EXIT },
        { "No", type::ACTION, placement::BODY, target::HOME },
    };


    opt[page::IDLE] = {
        { "", type::TEXT, placement::BODY },
    };
}


/*
----------------------------------------------------------------------------------------------------
Function Definition
----------------------------------------------------------------------------------------------------
*/
const std::vector<Options::Item>& Options::get(Navigation::PageId page) const {
    return opt.at(page);
}