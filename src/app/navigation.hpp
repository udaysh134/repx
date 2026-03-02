/**
 * @file navigation.hpp
 * @brief Navigation system for page flow control.
 *
 * Defines page identifiers and navigation stack handling.
 * Responsible for managing transitions between pages.
 */

#pragma once

#include <vector>
#include <string>


// ----------------------------------------------------------------------------------------------------
// Navigation Class - Page Flow Controller
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Manages navigation between application pages.
 *
 * Maintains a stack-based navigation history.
 * Handles entering new pages and returning to previous ones.
 */
class Navigation {
    public:
        /**
         * Unique identifiers for all application pages.
         * Used to determine current rendering and behavior logic.
         */
        enum class PageId {
            HOME,

            BROWSE, ///< Default browse page for NEW and OPEN pages.
            ERR_PAGE, ///< Default error page for any error display.
            SUCCESS, ///< Success pop-up page for any success from an action.
            CONFIRMATION, ///< Default dialog box for confirmation before proceeding.

            NEW,
            OPEN,

            ENTRIES, ///< To view all the entries saved.
            ENTRY_ADD,
            GEN_LB, ///< Page for automatic leaderboard generation.
            CONSOLE_HELP, ///< Page for help for command line.

            GEN_LB_WEEKLY,
            GEN_LB_MONTHLY,
            GEN_LB_YEARLY,
            GEN_LB_CUSTOM,

            SETTINGS,
            EXIT,

            IDLE ///< A placeholder page which does nothing.
        };

        /**
         * Contextual data passed along with a page.
         * Stores display-related information for a page instance.
         */
        struct PageContext {
            std::string pathLabel; ///< Display label for current path.
            std::string title; ///< Optional title of the page.
            std::string message; ///< Optional message shown on page.
        };

        // NavNode formed using PageId and PageContext ---------------------------------------- >>

        /**
         * Represents a single navigation entry.
         * Combines page identifier and its associated context.
         */
        struct NavNode {
            PageId page; ///< Identifier of the page.
            PageContext context; ///< Contextual data for the page.
        };


    public:
        /**
         * Initializes the navigation system with HOME page.
         * HOME page acts as a default landing ground for the user when program starts.
         */
        Navigation();

        // Navigation Controls ---------------------------------------- >>

        /**
         * Enters a new page and pushes it onto the navigation stack.
         *
         * @param[in] page Identifier of the page to enter (Use PageID enum).
         * @param[in] context Context data associated with the page (Use an object of strings).
         */
        void enter(PageId page, PageContext context = {});

        /**
         * Returns to the previous page if possible.
         */
        void back();

        // State Queries ---------------------------------------- >>

        /**
         * Retrieves the current navigation node.
         *
         * @return Reference to current NavNode containing : PageId (enum) and PageContext (struct).
         */
        const NavNode& current() const;

        /**
         * Checks whether back navigation is possible.
         *
         * @return TRUE if a previous page exists, otherwise FALSE.
         */
        bool canGoBack() const;

        /**
         * Determines whether navigation state indicates exit.
         *
         * @return TRUE if current page signals application exit.
         */
        bool shouldExit() const;

        /**
         * Builds breadcrumb path from navigation stack.
         *
         * @return Concatenated path string for breadcrumb display.
         */
        std::string breadCrumb() const;


    private:

        /**
         * Internal navigation stack storing page history.
         * Visual help on how it stores pages with navigation :
         * 
        ```
        {
            { HOME, { "home", "Main Menu", "The default page after program runs." } },
            { NEW, { "new", "Create Repboard", "Create a new repboard to start reputation collection." } },
            { BROWSE, { "browse", "", "" } }
        }
        ```
         * 
         * This preserves the history and details required per page for that page.
         */
        std::vector<NavNode> stack;
};