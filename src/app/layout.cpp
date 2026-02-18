// Headers
#include "layout.hpp"
#include "settings.hpp"


/*
----------------------------------------------------------------------------------------------------
Function Definition
----------------------------------------------------------------------------------------------------
*/
Layout::Geometry Layout::compute(int term_width, int term_height, int option_count) const {
    Geometry geo{};

    geo.term_width = term_width;
    geo.term_height = term_height;

    if (term_width < cfg.screen.min_W || term_height < cfg.screen.min_H) {
        geo.valid = false;
        return geo;
    }

    geo.valid = true;

    if (cfg.screen.layout.dynamicFrame) {
        geo.frame_width = term_width;
        geo.frame_height = term_height;
        geo.frame_x = 0;
        geo.frame_y = 0;
    } else {
        geo.frame_width = cfg.screen.min_W;
        geo.frame_height = cfg.screen.min_H;

        geo.frame_x = (term_width  - geo.frame_width) / 2;
        geo.frame_y = (term_height - geo.frame_height) / 2;
    }


    int header_h = cfg.screen.layout.height.h;
    int body_h = cfg.screen.layout.height.b;
    int footer_h = cfg.screen.layout.height.f;

    geo.header_y = geo.frame_y + 1;
    geo.body_y = geo.header_y + header_h;
    geo.footer_y = geo.body_y + body_h;

    geo.body_width = geo.frame_width - 2;
    geo.body_height = body_h;

    
    geo.option_rows.clear();

    if (option_count > 0) {
        int spacing = geo.body_height / option_count;

        for (int i = 0; i < option_count; i++) {
            int row = geo.body_y + (i * spacing);
            geo.option_rows.push_back(row);
        }
    }

    return geo;
}