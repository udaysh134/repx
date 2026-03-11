/**
 * @file engine.hpp
 * @brief Core engine entry interface.
 *
 * Provides the main start function for bootstrapping the application.
 */

#pragma once

#include "registry.hpp"
#include "layout.hpp"
#include "navigation.hpp"
#include "state.hpp"
#include "renderer.hpp"

// ----------------------------------------------------------------------------------------------------
// Engine Entry Point
// ----------------------------------------------------------------------------------------------------

/**
 * Initializes and runs the main application loop.
 *
 * Responsible for setting up core systems
 * and controlling overall program execution.
 */
void start();


// ----------------------------------------------------------------------------------------------------
// Helper Functions
// ----------------------------------------------------------------------------------------------------

/**
 * Redraws the updated screen on the terminal
 * 
 * @param[in] lyt Reference to the Layout class to be able to compute geometry.
 * @param[in] nav Reference to the Navigation class to fetch pages with pagination.
 * @param[in] registry Reference to the Registry class for page options and constext.
 * @param[in] state Reference to the State class to control the cursor movement.
 * @param[in] rdr Reference to the Renderer class to recompute everything and re-render after every function call.
 */
void updateFrame(
    Layout& lyt, 
    Navigation& nav, 
    Registry& registry,
    State& state, 
    Renderer& rdr
);