/**
 * @file registry.hpp
 * @brief Page registry system responsible  to provide template and structure for pages.
 *
 * Provides centralized storage and retrieval of page
 * configurations including context, options and handlers.
 */

#pragma once

#include <vector>
#include <unordered_map>

#include "navigation.hpp"
#include "state.hpp"
#include "options.hpp"

using PageId = Navigation::PageId;
using PageContext = Navigation::PageContext;


// ----------------------------------------------------------------------------------------------------
// Registry Class - Page Configuration Manager
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Stores and manages all page configurations.
 *
 * Each page is registered with its context, available options,
 * and optional behavior callbacks for enter, action and input events.
 */
class Registry {
    public:
        // Page Configuration ---------------------------------------- >>

        /**
         * @brief Configuration container for a page.
         *
         * Stores page identity, context data, available options,
         * and optional handler callbacks.
         */
        struct PageConfig {
            PageId id; ///< Unique page identifier.
            PageContext context; ///< Context information for the page (breadcrumb path label & footer message).

            std::vector<Options::Item> options; ///< Options displayed on the page to navigate around.

            void (*onEnter)(Navigation&, State&) = nullptr; ///< Optional callback triggered when page is entered.
            void (*onAction)(Navigation&, State&, const Options::Item&) = nullptr; ///< Optional callback triggered when an action option is activated.
            void (*onInput)(Navigation&, State&, int key) = nullptr; ///< Optional callback triggered during input handling.
        };

        /**
         * Registers a page configuration into the registry.
         *
         * @param[in] page The Page configuration struct to store with an individual page's own data.
         */
        static void registerPage(const PageConfig& page);

        // Auto Registration Helper ---------------------------------------- >>

        /**
         * Helper object used for automatic page registration.
         *
         * Instantiating this object automatically registers
         * the provided page configuration. Done using the econstructor.
         */
        struct PageRegistrar {
            PageRegistrar(const PageConfig& page) {
                Registry::registerPage(page);
            }
        };

        /**
         * Retrieves configuration of a page.
         *
         * @param[in] id Page identifier.
         * @return Reference to PageConfig struct, associated with the page.
         */
        const PageConfig& getPage(PageId id) const;


    private:
        /**
         * Internal container storing page configurations.
         *
         * @return Reference to the registry map.
         */
        static std::unordered_map<PageId, PageConfig>& getMap();
};