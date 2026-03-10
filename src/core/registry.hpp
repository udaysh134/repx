#pragma once

#include "navigation.hpp"
#include "state.hpp"
#include "options.hpp"

using PageId = Navigation::PageId;
using PageContext = Navigation::PageContext;


class Registry {
    public:
        using ctxFunc = PageContext (*)();

        struct PageHandler {
            ctxFunc context = nullptr;

            void (*onEnter)(Navigation&, State&) = nullptr;
            void (*onAction)(Navigation&, State&, const Options::Item&) = nullptr;
            void (*onInput)(Navigation&, State&, int key) = nullptr;
        };

        static void registerPage(PageId id, const PageHandler& handler);
        static const PageHandler& getHandler(PageId id);
    
    private:
        static std::unordered_map<PageId, PageHandler>& getMap();
};