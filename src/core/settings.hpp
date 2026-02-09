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
        const int min_H = 20;

        struct BoxBorder {
            struct Characters {
                const char *horz = "─"; // ─
                const char *vert = "│"; // │

                struct Corner {
                    const char *tl = "╭"; // ┌ ╭
                    const char *tr = "╮"; // ┐ ╮
                    const char *bl = "╰"; // └ ╰
                    const char *br = "╯"; // ┘ ╯
                } corner;
            } charac;
        } border;

        struct Layout {
            struct Height {
                const int h = 5;
                const int f = 7;
            } height;
        } layout;
    } screen;
};

extern DEF_CONFIG cfg;