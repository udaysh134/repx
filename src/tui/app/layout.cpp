// Headers
#include "layout.hpp"
#include "settings.hpp"


// ----------------------------------------------------------------------------------------------------
// Layout Geometry Computation
// ----------------------------------------------------------------------------------------------------

Layout::Geometry Layout::compute(int term_width, int term_height, int option_count) const {
    Geometry geo{};

    geo.term_width = term_width;
    geo.term_height = term_height;

    // Minimum Size Validation ---------------------------------------- >>

    if (term_width < cfg.screen.min_W || term_height < cfg.screen.min_H) {
        geo.valid = false;
        return geo;
    }

    geo.valid = true;

    // Determine Usable Area ---------------------------------------- >>

    int usable_width = term_width;
    int usable_height = term_height;

    if (!cfg.screen.layout.dynamicFrame) {
        usable_width = cfg.screen.min_W;
        usable_height = cfg.screen.min_H;
    }

    // Center Offset Calculation ---------------------------------------- >>

    int offset_x = (term_width - usable_width) / 2;
    int offset_y = (term_height - usable_height) / 2;

    // Taking Margin into consideration ---------------------------------------- >>

    int margin_h = cfg.screen.margin_Horz;
    int margin_v = cfg.screen.margin_Vert;

    int inner_width = usable_width - (margin_h * 2);
    int inner_height = usable_height - (margin_v * 2);

    // Safety: Ensure program fits inside margin-adjusted area
    if (inner_width <= 0 || inner_height <= 0) {
        geo.valid = false;
        return geo;
    }
    
    // Heights From Configuration ---------------------------------------- >>

    int header_h = cfg.screen.layout.height.h;
    int body_h;
    int footer_h = cfg.screen.layout.height.f;

    if (!cfg.screen.layout.dynamicFrame) {
        // Strict layout mode
        body_h = cfg.screen.layout.height.b;
    } else {
        // Dynamic layout mode
        body_h = inner_height - header_h - footer_h;

        if (body_h <= 0) {
            geo.valid = false;
            return geo;
        }
    }

    int total_program_height = header_h + body_h + footer_h;

    if (total_program_height > inner_height) {
        geo.valid = false;
        return geo;
    }

    // Starting point for entire program block ---------------------------------------- >>

    int program_x = offset_x + margin_h;
    int program_y = offset_y + margin_v;

    // Header Region
    geo.header.x = program_x;
    geo.header.y = program_y;
    geo.header.width = inner_width;
    geo.header.height = header_h;

    // Body Region
    geo.body.x = program_x;
    geo.body.y = geo.header.y + geo.header.height;
    geo.body.width = inner_width;
    geo.body.height = body_h;

    // Footer Region
    geo.footer.x = program_x;
    geo.footer.y = geo.body.y + geo.body.height;
    geo.footer.width = inner_width;
    geo.footer.height = footer_h;

    // Distribute Option Rows Inside Body ---------------------------------------- >>

    geo.option_rows.clear();
    geo.breadCrumb_row = geo.body.y + 1;

    if (option_count > 0) {
        // -2 for body borders (top & bottom)
        // -1 for breadcrumb row
        // -1 for the separator line
        int usable_body_height = geo.body.height - 4;

        if (usable_body_height > 0) {
            int gaps = option_count + 1;
            int spacing = usable_body_height / gaps;
            
            for (int i = 0; i < option_count; ++i) {
                int row = geo.breadCrumb_row + 2 + spacing * (i + 1);
                geo.option_rows.push_back(row);
            }
        }
    }

    return geo;
}