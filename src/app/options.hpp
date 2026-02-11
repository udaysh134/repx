#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "navigation.hpp"


class Menu {
    public:
        struct Option {
            std::string label;
            Navigation::PageId targetPage;
        };
    
        struct PageOptions {
            std::vector<Option> options;
        };
    
    public:
        Menu();
    
        void moveUp();
        void moveDown();
    
        int currentIndex() const;
        const std::vector<Option>& currentOptions(Navigation::PageId page) const;
    
        Navigation::PageId activate(Navigation::PageId page) const;
    
    private:
        std::unordered_map<Navigation::PageId, PageOptions> menus;
        int selectedIndex = 0;
};