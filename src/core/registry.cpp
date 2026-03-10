#include <stdexcept>
#include <unordered_map>

#include "registry.hpp"


void Registry::registerPage(PageId id, const PageHandler& handler) {
    getMap()[id] = handler;
}

const Registry::PageHandler& Registry::getHandler(PageId id) {
    auto &map = getMap();
    auto it = map.find(id);

    if (it == map.end()) {
        static PageHandler missing {
            []() {
                return PageContext{
                    "error",
                    "Page Missing",
                    ""
                };
            },
            nullptr,
            nullptr,
            nullptr
        };
        
        return missing;
    }

    return it->second;
}

std::unordered_map<PageId, Registry::PageHandler>& Registry::getMap() {
    static std::unordered_map<PageId, Registry::PageHandler> ctxMap;
    return ctxMap;
}