// Headers
#include "layout.hpp"
#include "settings.hpp"


/*
----------------------------------------------------------------------------------------------------
Main Function
----------------------------------------------------------------------------------------------------
*/
Layout::Geometry Layout::compute(int term_width, int term_height, int option_count) const {
    Geometry geo{};

    geo.term_width = term_width;
    geo.term_height = term_height;

    // Minimum Size Validation
    if (term_width < cfg.screen.min_W || term_height < cfg.screen.min_H) {
        geo.valid = false;
        return geo;
    }

    geo.valid = true;

    // Determine Usable Area
    int usable_width = term_width;
    int usable_height = term_height;

    if (!cfg.screen.layout.dynamicFrame) {
        usable_width = cfg.screen.min_W;
        usable_height = cfg.screen.min_H;
    }

    // Center if fixed
    int offset_x = (term_width - usable_width) / 2;
    int offset_y = (term_height - usable_height) / 2;


    // Heights from config
    int header_h = cfg.screen.layout.height.h;
    int body_h = cfg.screen.layout.height.b;
    int footer_h = cfg.screen.layout.height.f;

    // Optional margin from terminal edges
    int margin = 0;
    int box_width = usable_width - (margin * 2);

    // Header Region
    geo.header.x = offset_x + margin;
    geo.header.y = offset_y + margin;
    geo.header.width = box_width;
    geo.header.height = header_h;

    // Body Region
    geo.body.x = geo.header.x;
    geo.body.y = geo.header.y + geo.header.height;
    geo.body.width = box_width;
    geo.body.height = body_h;

    // Footer Region
    geo.footer.x = geo.body.x;
    geo.footer.y = geo.body.y + geo.body.height;
    geo.footer.width = box_width;
    geo.footer.height = footer_h;

    
    // 7. Distribute option rows inside body
    geo.option_rows.clear();

    if (option_count > 0) {
        int usable_body_height = geo.body.height - 2;

        if (usable_body_height > 0) {
            int spacing = usable_body_height / option_count;

            for (int i = 0; i < option_count; ++i) {
                int row = geo.body.y + 1 + (i * spacing);
                geo.option_rows.push_back(row);
            }
        }
    }

    return geo;
}