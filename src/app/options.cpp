// Headers
#include "options.hpp"
#include "navigation.hpp"

// Declarations
using page = Navigation::PageId;
using type = OptionRegistry::Type;
using placement = OptionRegistry::Placement;
using target = Navigation::PageId;


/*
----------------------------------------------------------------------------------------------------
Constructor Definition
----------------------------------------------------------------------------------------------------
*/
OptionRegistry::OptionRegistry() {
    options[page::HOME] = {
        { "Create New", type::ACTION, placement::BODY, target::BROWSE },
        { "Open Existing", type::ACTION, placement::BODY, target::BROWSE },
        { "Settings", type::ACTION, placement::BODY, target::SETTINGS },
        { "Exit", type::ACTION, placement::BODY, target::EXIT },
    };
    

    options[page::BROWSE] = {
        { "Select File", type::ACTION, placement::BODY },
        { "Path", type::INPUT, placement::BODY },
    };


    options[page::ERROR] = {
        { "Ok", type::ACTION, placement::BODY },
    };


    options[page::SUCCESS] = {
        { "Ok", type::ACTION, placement::BODY },
    };


    options[page::CONFIRMATION] = {
        { "Yes", type::ACTION, placement::BODY },
        { "No", type::ACTION, placement::BODY },
    };


    options[page::NEW] = {
        { "Name", type::INPUT, placement::BODY },
        { "Description", type::INPUT, placement::BODY },
        { "Author", type::INPUT, placement::BODY },

        { "Save", type::ACTION, placement::FOOTER, target::HOME },
        { "Cancel", type::ACTION, placement::FOOTER, target::HOME },
    };


    options[page::OPEN] = {
        { "View Entries", type::ACTION, placement::BODY, target::ENTRIES },
        { "Add an Entry", type::ACTION, placement::BODY, target::ENTRY_ADD },
        { "Generate Leaderboard", type::ACTION, placement::BODY, target::GEN_LB },
        { "?", type::ACTION, placement::BODY, target::CONSOLE_HELP },

        { "Console", type::INPUT, placement::FOOTER },
    };


    options[page::ENTRIES] = {
        { "", type::TEXT, placement::BODY },
        { "Back", type::ACTION, placement::FOOTER, target::OPEN },
    };


    options[page::ENTRY_ADD] = {
        { "Name", type::INPUT, placement::BODY },
        { "Increase", type::SELECTION, placement::BODY },
        { "Decrease", type::SELECTION, placement::BODY },
        { "Reason", type::INPUT, placement::BODY },

        { "Save", type::ACTION, placement::FOOTER, target::SUCCESS },
        { "Cancel", type::ACTION, placement::FOOTER, target::OPEN },
    };


    options[page::GEN_LB] = {
        { "Weekly", type::ACTION, placement::BODY, target::GEN_LB_WEEKLY },
        { "Monthly", type::ACTION, placement::BODY, target::GEN_LB_MONTHLY },
        { "Yearly", type::ACTION, placement::BODY, target::GEN_LB_YEARLY },

        { "Custom", type::ACTION, placement::FOOTER, target::GEN_LB_CUSTOM },
    };


    options[page::CONSOLE_HELP] = {
        { "", type::TEXT, placement::BODY },
        { "Back", type::ACTION, placement::FOOTER, target::OPEN },
    };


    options[page::GEN_LB_WEEKLY] = {
        { "This Week", type::ACTION, placement::BODY },
        { "Last Week", type::ACTION, placement::BODY },
    };


    options[page::GEN_LB_MONTHLY] = {
        { "This Month", type::ACTION, placement::BODY },
        { "Last Month", type::ACTION, placement::BODY },
    };


    options[page::GEN_LB_YEARLY] = {
        { "This Year", type::ACTION, placement::BODY },
        { "Last Year", type::ACTION, placement::BODY },
    };


    options[page::GEN_LB_CUSTOM] = {
        { "Start Date", type::INPUT, placement::BODY },
        { "End Date", type::INPUT, placement::BODY },

        { "Ok", type::ACTION, placement::FOOTER, target::SUCCESS },
        { "Cancel", type::ACTION, placement::FOOTER, target::GEN_LB },
    };


    options[page::SETTINGS] = {
        { "Back", type::ACTION, placement::FOOTER, target::HOME },
    };


    options[page::EXIT] = {
        { "Yes", type::ACTION, placement::BODY, target::EXIT },
        { "No", type::ACTION, placement::BODY, target::HOME },
    };


    options[page::IDLE] = {
        { "", type::TEXT, placement::BODY },
    };
}