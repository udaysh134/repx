#pragma once

#include <string>

struct DEF_CONFIG {
    /*
    ----------------------------------------------------------------------------------------------------
    Pragram Configurations
    ----------------------------------------------------------------------------------------------------
    */
    struct Program {
        const char *name = "RepX";
        const char *version = "v0.0.0";
    } program;

    /*
    ----------------------------------------------------------------------------------------------------
    Screen Configurations
    ----------------------------------------------------------------------------------------------------
    */
    struct Screen {
        const int min_W = 60;
        const int min_H = 20;

        struct BoxBorder {
            const char *horz = "─";
            const char *vert = "│";

            struct Corners {
                const std::string flat[4] = {"┌", "┐", "└", "┘"};
                const std::string rounded[4] = {"╭", "╮", "╰", "╯"};
            } corners;
        } border;

        struct Layout {
            const bool dynamicFrame = true;

            struct Height {
                const int h = 3;
                const int b = 11;
                const int f = 5;
            } height;
        } layout;
    } screen;
};

extern DEF_CONFIG cfg;