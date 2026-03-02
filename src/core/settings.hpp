/**
 * @file settings.hpp
 * @brief Global configuration definitions for RepX.
 *
 * Defines program identity, screen configuration,
 * layout settings, border styles and a lot more.
 */

#pragma once

#include <string>

#include "utils.hpp"

// ----------------------------------------------------------------------------------------------------
// Global Configuration Structure
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Central configuration container for application settings.
 *
 * Stores program information, screen constraints,
 * layout behavior, visual border definitions, etc.
 */
struct DEF_CONFIG {
    // Program Configurations ---------------------------------------- >>

    struct Program {
        const char* name = "RepX"; ///< Program name.
        const char* version = "v0.0.0"; ///< Program version string.

        struct Prefix {
            const std::string action = "> "; ///< Default moving icon like character during hover.
            const std::string input = " : "; ///< Prefix for Input fields.
            const std::string selection = "[x] "; ///< Default prefix to represent selection of a SELECTION type button.
        } prefix;
    } program;

    // Screen Configurations ---------------------------------------- >>

    struct Screen {
        const int min_W = 60; ///< Minimum required terminal width.
        const int min_H = 25; ///< Minimum required terminal height.
        const int margin_Vert = 0; ///< Vertical margin from terminal edges.
        const int margin_Horz = 0; ///< Horizontal margin from terminal edges.

        // Border Definitions

        struct BoxBorder {
            const char* horz = "─"; ///< Horizontal border character.
            const char* vert = "│"; ///< Vertical border character.

            struct Corners {
                struct Flat {
                    const char* tl = "┌";
                    const char* tr = "┐";
                    const char* bl = "└";
                    const char* br = "┘";
                } flat;

                struct Rounded {
                    const char* tl = "╭";
                    const char* tr = "╮";
                    const char* bl = "╰";
                    const char* br = "╯";
                } rounded;
            } corner;
        } border;


        // Layout Settings

        struct Layout {
            const bool dynamicFrame = true; ///< TRUE for dynamic resizing, FALSE for fixed frame.

            struct Height {
                const int h = 5; ///< Header height.
                const int b = 13; ///< Body height.
                const int f = 7; ///< Footer height.
            } height;
        } layout;
    } screen;
};


// ----------------------------------------------------------------------------------------------------
// Global Configuration Instance
// ----------------------------------------------------------------------------------------------------

/**
 * Global configuration instance.
 */
extern DEF_CONFIG cfg;