#include <unordered_map>

#include "registry.hpp"


void Registry::registerPage(const PageConfig& pageCFG) {
    getMap()[pageCFG.id] = pageCFG;
}

const Registry::PageConfig& Registry::getPage(PageId id) const {
    auto &map = getMap();
    auto it = map.find(id);

    if (it == map.end()) {
        static PageConfig missing {
            PageId::IDLE,
            {
                "error",
                "Page Missing"
            },
            {
                // No Options
            },
            nullptr,
            nullptr,
            nullptr
        };

        return missing;
    }

    return it->second;
}

std::unordered_map<PageId, Registry::PageConfig>& Registry::getMap() {
    static std::unordered_map<PageId, Registry::PageConfig> pageMap;
    return pageMap;
}