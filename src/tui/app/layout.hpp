/**
 * @file layout.hpp
 * @brief Layout computation for terminal regions.
 *
 * Defines the Layout class and Geometry structure.
 * Responsible for calculating header, body, footer regions.
 */

#pragma once

#include <vector>


// ----------------------------------------------------------------------------------------------------
// Layout Class - Main entry point for Layout Geometry System
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Computes structured layout regions for the visible terminal.
 *
 * Generates header, body, footer regions along with option row positions.
 * Validates terminal size against minimum configuration constraints.
 */
class Layout {
    public:
        // Struct containing variables, where geometrical data is stored ---------------------------------------- >>

        /**
         * Holds computed layout information.
         * 
        ```
         * valid : Container to check and allow/disallow box layout computation.
         * term_width : Stores visible terminal's width.
         * term_height : Stores visible terminal's height.
         * Region : Struct layouts from which header/body/footer boxes are formed.
         * header : Variable to store/access computation data for Header Box.
         * body : Variable to store/access computation data for Body Box.
         * footer : Variable to store/access computation data for Footer Box.
         * breadCrumb_row : Variable for storing string of path labels with slashes, to display page navigation on top.
         * option_rows : Sequential y-coords stored in a vector for the display of clickable options in a menu page with even spacing.
        ```
         */
        struct Geometry {
            bool valid; ///< Checks the validity of whole logic computation. Will return, if FALSE (where terminal dimension < minimum required), will compute, if TRUE.

            int term_width; ///< Stores the calculated terminal width.
            int term_height; ///< Stores the calculated terminal height.

            /**
             * Defines a rectangular region.
             * Represents a box with position and dimensions.
             */
            struct Region {
                int x;
                int y;
                int width;
                int height;
            };

            Region header; ///< Variable to store/access computation data for Header Box. "Region" struct containing : x, y, width, height.
            Region body; ///< Variable to store/access computation data for Body Box. "Region" struct containing : x, y, width, height.
            Region footer; ///< Variable to store/access computation data for Footer Box. "Region" struct containing : x, y, width, height.

            int breadCrumb_row; ///< Y-coordinate where breadcrumb will be rendered inside body.

            std::vector<int> option_rows; ///< Sequential y-coordinates for evenly spaced option rows inside the body region.
        };


        // Function responsible to calculate the geometry and store data ---------------------------------------- >>

        /**
         * Computes layout regions based on terminal size and option count.
         *
         * @param[in] term_width Width of terminal in columns.
         * @param[in] term_height Height of terminal in rows.
         * @param[in] option_count Number of options to distribute in body section.
         *
         * @return "Geometry" struct containing :
         * 
        ```
         * valid
         * term_width
         * term_height
         * header
         * body
         * footer
         * option_rows
        ```
         */
        Geometry compute(int term_width, int term_height, int option_count) const;
};