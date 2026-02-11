#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "navigation.hpp"

class OptionRegistry {
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
        OptionRegistry();
        const std::vector<Item>& get(Navigation::PageId page) const;

    private:
        std::unordered_map<Navigation::PageId, std::vector<Item>> options;
};