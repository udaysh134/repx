#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "navigation.hpp"

class Options {
    public:
        enum class Type { ACTION, INPUT, TEXT, SELECTION };
        enum class Placement { BODY, FOOTER };

        struct Item {
            std::string label;
            Type type;
            Placement placement;
            Navigation::PageId targetPage = Navigation::PageId::IDLE;
        };

    public:
        Options();
        const std::vector<Item>& get(Navigation::PageId page) const;

    private:
        std::unordered_map<Navigation::PageId, std::vector<Item>> opt;
};