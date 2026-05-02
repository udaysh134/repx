/**
 * @file renderer.hpp
 * @brief Rendering system for terminal UI.
 *
 * Responsible for drawing layout regions,
 * options, and page-specific content.
 */

#pragma once

#include <vector>
#include <string>

#include "layout.hpp"
#include "state.hpp"
#include "options.hpp"
#include "navigation.hpp"

// ----------------------------------------------------------------------------------------------------
// Renderer Class - Terminal Drawing Engine
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Handles visual rendering of layout and TUI elements.
 *
 * Uses Layout::Geometry, State and Options from 
 * respective classes to draw header, body, footer, and selectable options.
 */
class Renderer {
    public:
        /**
         * Renders the complete page layout.
         *
         * @param[in] geo Computed layout geometry (using reference of Geometry from layout.hpp).
         * @param[in] state Current application state (using reference of State class from state.hpp).
         * @param[in] options List of options associated with current page (using reference of Item in vector from options.hpp).
         * @param[in] nav Reference of Navigation class, to retrieve breadcrumb data from nav.stack().
         * @param[in] ctx Reference of "context" object from each page to retrieve contextual information.
         */
        void render(
            const Layout::Geometry& geo,
            const State& state,
            const std::vector<Options::Item>& options,
            const Navigation& nav,
            const Navigation::PageContext& ctx
        );

        /**
         * Clears the terminal screen using Windows API and not system("cls").
         */
        static void clrScreen();


    private:
        /**
         * Draws a rectangular box.
         *
         * @param[in] x Starting x-coordinate of box.
         * @param[in] y Starting y-coordinate of box.
         * @param[in] w Total width of the box.
         * @param[in] h Total height of the box.
         */
        void drawBox(int x, int y, int w, int h) const;

        // Draw Header, Body and Footer ---------------------------------------- >>

        /**
         * Draws header region with program's Title and Version.
         *
         * @param[in] geo Computed layout geometry.
         */
        void drawHeader(const Layout::Geometry& geo) const;

        /**
         * Draws body region and its options.
         *
         * @param[in] geo Computed layout geometry.
         * @param[in] state Current application state.
         * @param[in] options Options to render inside body.
         */
        void drawBody(
            const Layout::Geometry& geo,
            const State& state,
            const std::vector<Options::Item>& options,
            const std::string& breadCrumb
        ) const;

        /**
         * Draws footer region and its options (if available).
         *
         * @param[in] geo Computed layout geometry.
         * @param[in] state Current application state.
         * @param[in] options Options to render inside footer.
         * @param[in] ctx Contextual data to render inside footer (especially footer message).
         */
        void drawFooter(
            const Layout::Geometry& geo,
            const State& state,
            const std::vector<Options::Item>& options,
            const Navigation::PageContext& ctx
        ) const;

        // Draw options with labels, state, cursor etc for each page ---------------------------------------- >>

        /**
         * Draws a single option entry.
         *
         * @param[in] geo Layout geometry reference.
         * @param[in] opt Option item to render.
         * @param[in] y Y-coordinate where option will be placed.
         * @param[in] selected TRUE if currently selected (decides if cursor highlights or not).
         * @param[in] state Current application state (button specific).
         * @param[in] optionIndex Index of the option in the list.
         */
        void drawOption(
            const Layout::Geometry& geo,
            const Options::Item& opt,
            int y,
            bool selected,
            const State& state,
            std::size_t optionIndex
        ) const;
};