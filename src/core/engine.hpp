/**
 * @file engine.hpp
 * @brief Core engine entry interface.
 *
 * Provides the main start function for bootstrapping the application.
 */

#pragma once

#include "layout.hpp"
#include "navigation.hpp"
#include "options.hpp"
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
 * 
 */
void updateFrame(
    Layout& lyt, 
    Navigation& nav, 
    Options& opt, 
    State& state, 
    Renderer& rdr
);