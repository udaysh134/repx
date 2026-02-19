#pragma once

#include <vector>

#include "layout.hpp"
#include "state.hpp"
#include "options.hpp"

class Renderer {
    public:
        void render(const Layout::Geometry& geo, const State& state, const std::vector<Options::Item>& options);

    private:
        void clrScreen() const;
        void drawBox(int x, int y, int w, int h) const;

        void drawHeader(const Layout::Geometry& geo) const;
        void drawBody(const Layout::Geometry& geo, const State& state, const std::vector<Options::Item>& options) const;
        void drawFooter(const Layout::Geometry& geo, const State& state, const std::vector<Options::Item>& options) const;

        void drawOption(const Layout::Geometry& geo, const Options::Item& opt, int y, bool selected, const State& state, std::size_t optionIndex) const;
};