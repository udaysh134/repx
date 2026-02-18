#pragma once

#include <vector>

class Layout {
    public:
        struct Geometry {
            bool valid;
            
            int term_width;
            int term_height;

            int frame_x;
            int frame_y;
            int frame_width;
            int frame_height;

            int header_y;
            int body_y;
            int footer_y;

            int body_width;
            int body_height;

            std::vector<int> option_rows;
        };

        Geometry compute(int term_width, int term_height, int option_count) const;
};