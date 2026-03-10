#include <stdexcept>

#include "pageReg.hpp"


void Registry::registerPage(PageId id, ctxFunc func) {
    getMap()[id] = func;
}

PageContext Registry::getContext(PageId id) {
    auto &map = getMap();
    
    auto it = map.find(id);
    if (it == map.end()) {
        return {"error", "Page missing", ""};
    }

    return it->second();
}

std::unordered_map<PageId, Registry::ctxFunc>& Registry::getMap() {
    static std::unordered_map<PageId, ctxFunc> ctxMap;
    return ctxMap;
}