/**
 * @file options.hpp
 * @brief Option configuration system for application pages.
 *
 * Defines selectable items associated with each page.
 * Responsible for storing and retrieving page-based options.
 */

#pragma once

#include <string>
#include <vector>
#include <string_view>

#include "navigation.hpp"


// ----------------------------------------------------------------------------------------------------
// Options ID
// ----------------------------------------------------------------------------------------------------

namespace OptionId {
    inline constexpr std::string_view HOME_CREATE_NEW = "home-crt_new";
    inline constexpr std::string_view HOME_OPEN_EXISTING = "home-opn_exst";
    inline constexpr std::string_view HOME_SETTINGS = "home-stngs";
    inline constexpr std::string_view HOME_EXIT = "home-ext";
    inline constexpr std::string_view NEW_SELECT_DIRECTORY = "new-slct_dir";
    inline constexpr std::string_view NEW_FOLDER_PATH = "new-fldr_pth";
    inline constexpr std::string_view OPEN_SELECT_FILE = "open-slct_file";
    inline constexpr std::string_view OPEN_FILE_PATH = "open-file_pth";
    inline constexpr std::string_view SETTINGS_SHARP_BORDERS = "settings-shrp_brdr";
    inline constexpr std::string_view SETTINGS_CURSOR_AS_BOX = "settings-crsr_box";
    inline constexpr std::string_view SETTINGS_DYNAMIC_RESIZE = "settings-dynm_res";
    inline constexpr std::string_view EXIT_YES = "exit-yes";
    inline constexpr std::string_view EXIT_CANCEL = "exit-cncl";
};


// ----------------------------------------------------------------------------------------------------
// Options Class - Page Option Manager
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Manages available options for each navigation page.
 *
 * Maps PageId to a collection of selectable items.
 * Used to determine what options are rendered on a page.
 */
class Options {
    public:
        /**
         * Defines behavior type of an option.
         */
        enum class Type {
            ACTION,
            INPUT,
            TEXT, ///< Button type to only view, no interaction.
            SELECTION ///< Checkbox style button to select or unselect an option.
        };

        /**
         * Defines where an option is placed in layout.
         */
        enum class Placement {
            BODY,
            FOOTER
        };

        // Option Item Structure ---------------------------------------- >>

        /**
         * Represents a single selectable option.
         *
         * Stores display label, type, placement.
         * Also stores optional target navigation page.
         */
        struct Item {
            std::string label; ///< Display label of the option.
            std::string_view id; ///< Defines a unique id (aligning with the label name) from which this option can be accessed.
            Type type; ///< Behavior type of the option.
            Placement placement; ///< Layout placement (BODY or FOOTER).
            Navigation::PageId targetPage = Navigation::PageId::IDLE; ///< Target page for navigation actions.
        };
};