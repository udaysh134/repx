// Headers
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

#include "renderer.hpp"
#include "settings.hpp"
#include "utils.hpp"


// ----------------------------------------------------------------------------------------------------
// Public Functions
// ----------------------------------------------------------------------------------------------------

// Render Page ---------------------------------------- >>

void Renderer::render(
    const Layout::Geometry& geo,
    const State& state,
    const std::vector<Options::Item>& options,
    const Navigation& nav
) {
    Renderer::clrScreen();

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
    drawBody(geo, state, options, nav.breadCrumb());
    drawFooter(geo, state, options);
}


// ----------------------------------------------------------------------------------------------------
// Private Functions
// ----------------------------------------------------------------------------------------------------

// Clear Screen ---------------------------------------- >>

void Renderer::clrScreen() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);

    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD count;
    COORD homeCoords = { 0, 0 };

    // Fill entire screen with spaces
    FillConsoleOutputCharacter(hOut, ' ', cellCount, homeCoords, &count);

    // Reset attributes
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, cellCount, homeCoords, &count);

    // Move cursor back to top-left
    SetConsoleCursorPosition(hOut, homeCoords);
}

// Draw Box ---------------------------------------- >>

void Renderer::drawBox(int x, int y, int w, int h) const {
    const char* horz = cfg.screen.border.horz;
    const char* vert = cfg.screen.border.vert;

    const std::string tl = cfg.screen.border.corner.rounded.tl;
    const std::string tr = cfg.screen.border.corner.rounded.tr;
    const std::string bl = cfg.screen.border.corner.rounded.bl;
    const std::string br = cfg.screen.border.corner.rounded.br;

    // Horizontal and Verical Lines
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

    // Building Corners
    console::mvCursor(x, y);
    std::cout << tl;
    console::mvCursor(x + w - 1, y);
    std::cout << tr;
    console::mvCursor(x, y + h - 1);
    std::cout << bl;
    console::mvCursor(x + w - 1, y + h - 1);
    std::cout << br;
}

// Draw Header ---------------------------------------- >>

void Renderer::drawHeader(const Layout::Geometry& geo) const {
    std::string title = std::string(cfg.program.name) + " " + std::string(cfg.program.version);

    int contentY = geo.header.y + geo.header.height / 2;
    int contentStartX = geo.header.x + 1;
    int contentWidth = geo.header.width - 2;

    int titleX = contentStartX + (contentWidth - title.length()) / 2;

    console::mvCursor(titleX, contentY);
    std::cout << title;
}

// Draw Body ---------------------------------------- >>

void Renderer::drawBody(
    const Layout::Geometry& geo,
    const State& state,
    const std::vector<Options::Item>& options,
    const std::string& breadCrumb
) const {
    // Draw Bread Crumb

    console::mvCursor(geo.body.x + 3, geo.breadCrumb_row);
    std::cout << breadCrumb;

    // Draw separator Line

    int sepY = geo.breadCrumb_row + 1;

    int startX = geo.body.x + 1;
    int endX = geo.body.x + geo.body.width - 2;

    console::mvCursor(startX, sepY);

    for (int i = startX; i <= endX; ++i) {
        std::cout << "-";
    }

    // Draw Options
    
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

// Draw Footer ---------------------------------------- >>

void Renderer::drawFooter(
    const Layout::Geometry& geo,
    const State& state,
    const std::vector<Options::Item>& options
) const {
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

// Draw a single Option label ---------------------------------------- >>

void Renderer::drawOption(
    const Layout::Geometry& geo,
    const Options::Item& opt,
    int y,
    bool selected,
    const State& state,
    std::size_t optionIndex
) const {
    int content_width = geo.body.width - 2;
    int text_width = static_cast<int>(opt.label.length());

    // Account for prefixes like "> " or "[x] "
    int prefix_width = 0;

    switch (opt.type) {
        case Options::Type::ACTION:
            prefix_width = 2; // "> "
            break;
        case Options::Type::SELECTION:
            prefix_width = 4; // "[x] "
            break;
        case Options::Type::INPUT:
            prefix_width = 3; // " : "
            break;
        default:
            prefix_width = 0;
    }

    int total_width = prefix_width + text_width;

    int x = geo.body.x + 1 + (content_width - total_width) / 2;
    console::mvCursor(x, y);

    std::string prefix_ACTION = cfg.program.prefix.action;
    std::string prefix_INPUT = cfg.program.prefix.input;
    std::string prefix_SELECTION = cfg.program.prefix.selection;

    switch (opt.type) {
        case Options::Type::ACTION: {
            std::cout << (selected ? prefix_ACTION : "  ");
            std::cout << opt.label;
            break;
        }

        case Options::Type::INPUT: {
            std::cout << opt.label << prefix_INPUT;
            std::cout << state.buffer();

            if (selected && state.isEditing()) std::cout << "|";
            break;
        }

        case Options::Type::SELECTION: {
            bool isSelected = state.isSelected(optionIndex);

            std::cout << (isSelected ? prefix_SELECTION : "[ ] ");
            std::cout << opt.label;
            break;
        }

        case Options::Type::TEXT: {
            std::cout << opt.label;
            break;
        }
    }
}