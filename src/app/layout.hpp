#pragma once

#include <vector>

class Layout {
    public:
        struct Geometry {
            bool valid;
            
            int term_width;
            int term_height;

            struct Region {
                int x;
                int y;
                int width;
                int height;
            };

            Region header;
            Region body;
            Region footer;

            std::vector<int> option_rows;
        };

        Geometry compute(int term_width, int term_height, int option_count) const;
};