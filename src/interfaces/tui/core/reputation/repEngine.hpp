/**
 * @file repEngine.hpp
 * @brief Reputation Engine Interface - Handles external interaction points for reputation system
 */

#pragma once

#include <string>

/**
 * @brief Core interface for reputation system interactions
 *
 * This namespace exposes high-level functions that act as entry points
 * for interacting with the reputation system. It abstracts platform-specific
 * implementations (e.g., file dialogs) away from the rest of the system.
 */
namespace RepEngine {

    // ----------------------------------------------------------------------------------------------------
    // Input / Output Utilities
    // ----------------------------------------------------------------------------------------------------

    /*
     * Opens a native directory selection dialog and returns the selected path.
     *
     * @return Selected directory path as UTF-8 string 
     * Returns empty string if user cancels or operation fails.
     */
    std::string select_directory();

    /*
     * Opens a native file selection dialog and returns the selected file path.
     *
     * @return Selected file path as UTF-8 string
     * Returns empty string if user cancels or operation fails
     */
    std::string select_file();
}