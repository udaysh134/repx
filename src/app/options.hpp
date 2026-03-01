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
#include <unordered_map>

#include "navigation.hpp"


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
            Type type; ///< Behavior type of the option.
            Placement placement; ///< Layout placement (BODY or FOOTER).
            Navigation::PageId targetPage = Navigation::PageId::IDLE; ///< Target page for navigation actions.
        };


    public:
        /**
         * Initializes all option labels with actions they hold, for all configuration mapping.
         */
        Options();

        // Retrieve Options ---------------------------------------- >>

        /**
         * Retrieves options associated with a specific page.
         *
         * @param[in] page Page identifier.
         * @return Constant reference to vector of Item.
         */
        const std::vector<Item>& get(Navigation::PageId page) const;


    private:
        /**
         * Internal storage mapping PageId to corresponding options.
         * 
         * Maps as : 
         * OPTION's LABEL -> OPTION's METADATA (Type, Placement, Target)
         */
        std::unordered_map<Navigation::PageId, std::vector<Item>> opt;
};