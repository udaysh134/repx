#pragma once

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
        const int min_H = 19;

        struct BoxBorder {
            const char *horz = "─";
            const char *vert = "│";

            struct Corners {
                struct Flat {
                    const char *tl = "┌";
                    const char *tr = "┐";
                    const char *bl = "└";
                    const char *br = "┘";
                } flat;
                
                struct Rounded {
                    const char *tl = "╭";
                    const char *tr = "╮";
                    const char *bl = "╰";
                    const char *br = "╯";
                } rounded;
            } corner;
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