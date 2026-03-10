#pragma once

#include <unordered_map>

#include "navigation.hpp"

using PageId = Navigation::PageId;
using PageContext = Navigation::PageContext;


class Registry {
    public:
        using ctxFunc = PageContext (*)();

        static void registerPage(PageId id, ctxFunc func);
        static PageContext getContext(PageId id);
    
    private:
        static std::unordered_map<PageId, ctxFunc>& getMap();

    private:
        static std::unordered_map<PageId, ctxFunc> ctxMap;
};