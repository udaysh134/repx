#pragma once

#include <vector>
#include <unordered_map>

#include "navigation.hpp"
#include "state.hpp"
#include "options.hpp"

using PageId = Navigation::PageId;
using PageContext = Navigation::PageContext;


class Registry {
    public:
        struct PageConfig {
            PageId id;
            PageContext context;

            std::vector<Options::Item> options;

            void (*onEnter)(Navigation&, State&) = nullptr;
            void (*onAction)(Navigation&, State&, const Options::Item &) = nullptr;
            void (*onInput)(Navigation&, State&, int key) = nullptr;
        };

        static void registerPage(const PageConfig& page);

        struct PageRegistrar {
            PageRegistrar(const PageConfig &page) {
                Registry::registerPage(page);
            }
        };

        const PageConfig& getPage(PageId id) const;
    
    private:
        static std::unordered_map<PageId, PageConfig>& getMap();
};