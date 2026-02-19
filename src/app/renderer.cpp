// Headers
#include <iostream>
#include <string>
#include <algorithm>

#include "renderer.hpp"
#include "settings.hpp"
#include "utils.hpp"


/*
----------------------------------------------------------------------------------------------------
Public Functions
----------------------------------------------------------------------------------------------------
*/
void Renderer::render(const Layout::Geometry& geo, const State& state, const std::vector<Options::Item>& options) {
    clrScreen();

    if (!geo.valid) {
        std::string errLine_1 = "Error : Terminal too small";
        std::string errLine_2 = "Minimum required screen size : " + std::to_string(cfg.screen.min_W) + " x " + std::to_string(cfg.screen.min_H);

        int centerY = geo.term_height / 2;

        int err1X = (geo.term_width - errLine_1.length()) / 2;
        int err2X = (geo.term_width - errLine_2.length()) / 2;

        console::mvCursor(err1X, centerY - 1);
        std::cout << color::RED << errLine_1 << color::RESET;

        console::mvCursor(err2X, centerY);
        std::cout << color::BLUE << errLine_2 << color::RESET;

        return;
    }

    drawBox(geo.header.x, geo.header.y, geo.header.width, geo.header.height);
    drawBox(geo.body.x, geo.body.y, geo.body.width, geo.body.height);
    drawBox(geo.footer.x, geo.footer.y, geo.footer.width, geo.footer.height);

    drawHeader(geo);
    drawBody(geo, state, options);
    drawFooter(geo, state, options);
}


/*
----------------------------------------------------------------------------------------------------
Private Functions
----------------------------------------------------------------------------------------------------
*/
void Renderer::clrScreen() const {
    console::mvCursor(0, 0);
}

void Renderer::drawBox(int x, int y, int w, int h) const {
    const char* horz = cfg.screen.border.horz;
    const char* vert = cfg.screen.border.vert;

    const std::string tl = cfg.screen.border.corner.rounded.tl;
    const std::string tr = cfg.screen.border.corner.rounded.tr;
    const std::string bl = cfg.screen.border.corner.rounded.bl;
    const std::string br = cfg.screen.border.corner.rounded.br;

    console::mvCursor(x, y);
    for (int i = 0; i < w; ++i) std::cout << horz;
    
    for (int i = 1; i < h - 1; ++i) {
        console::mvCursor(x, y + i);
        std::cout << vert;
        console::mvCursor(x + w - 1, y + i);
        std::cout << vert;
    }

    console::mvCursor(x, y + h - 1);
    for (int i = 0; i < w; ++i) std::cout << horz;

    console::mvCursor(x, y);
    std::cout << tl;
    console::mvCursor(x + w - 1, y);
    std::cout << tr;
    console::mvCursor(x, y + h - 1);
    std::cout << bl;
    console::mvCursor(x + w - 1, y + h - 1);
    std::cout << br;
}

void Renderer::drawHeader(const Layout::Geometry& geo) const {
    std::string title = std::string(cfg.program.name) + " " + std::string(cfg.program.version);

    int contentY = geo.header.y + geo.header.height / 2;
    int contentStartX = geo.header.x + 1;
    int contentWidth = geo.header.width - 2;

    int titleX = contentStartX + (contentWidth - title.length()) / 2;

    console::mvCursor(titleX, contentY);
    std::cout << title;
}

void Renderer::drawBody(const Layout::Geometry& geo, const State& state, const std::vector<Options::Item>& options) const {
    std::size_t bodyIndex = 0;

    for (std::size_t i = 0; i < options.size(); ++i) {
        if (options[i].placement != Options::Placement::BODY) continue;

        bool selected = (i == state.index());

        if (bodyIndex < geo.option_rows.size()) {
            int row = geo.option_rows[bodyIndex];
            drawOption(geo, options[i], row, selected, state, i);
            bodyIndex++;
        }
    }
}

void Renderer::drawFooter(const Layout::Geometry& geo, const State& state, const std::vector<Options::Item>& options) const {
    int y = geo.footer.y + 1;
    int x = geo.footer.x + 2;

    for (std::size_t i = 0; i < options.size(); ++i) {
        if (options[i].placement != Options::Placement::FOOTER) continue;

        bool selected = (i == state.index());

        console::mvCursor(x, y);
        std::cout << (selected ? "> " : "  ");
        std::cout << options[i].label;

        x += options[i].label.length() + 4;
    }
}

void Renderer::drawOption(const Layout::Geometry& geo, const Options::Item& opt, int y, bool selected, const State& state, std::size_t optionIndex) const {
    int x = geo.body.x + 2;
    console::mvCursor(x, y);

    switch (opt.type) {
        case Options::Type::ACTION: {
            std::cout << (selected ? "> " : "  ");
            std::cout << opt.label;
            break;
        }

        case Options::Type::INPUT: {
            std::cout << opt.label << " : ";
            std::cout << state.buffer();

            if (selected && state.isEditing()) std::cout << "|";
            break;
        }

        case Options::Type::SELECTION: {
            bool isSelected = state.isSelected(optionIndex);

            std::cout << (isSelected ? "[x] " : "[ ] ");
            std::cout << opt.label;
            break;
        }

        case Options::Type::TEXT: {
            std::cout << opt.label;
            break;
        }
    }
}