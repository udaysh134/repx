#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "navigation.hpp"

class Options {
    public:
        struct Item {
            std::string label;
            Navigation::PageId targetPage;
        };

        struct PageItems {
            std::vector<Item> pageItems;
        };

    public:
        Options();

        void moveUp();
        void moveDown();

        int currentIndex() const;
        const std::vector<Item>& currentItems(Navigation::PageId page) const;

        Navigation::PageId activate(Navigation::PageId page) const;

    private:
        std::unordered_map<Navigation::PageId, PageItems> pages;
        int selectedIndex = 0;
};