#pragma once

#include <string>
#include <cstddef>
#include <unordered_set>

class State {
    public:    
        std::size_t index() const;
        void moveUp(std::size_t itemCount);
        void moveDown(std::size_t itemCount);    
        void reset();
    
        void startEditing();
        void stopEditing();
        bool isEditing() const;
    
        void appendChar(char c);
        void removeChar();
        const std::string& buffer() const;

        void toggleSelection(std::size_t itemIndex);
        bool isSelected(std::size_t itemIndex) const;
    
    private:
        bool editing = false;
        
        std::size_t selectedIndex = 0;
        std::string inputBuffer;

        std::unordered_set<std::size_t> selectedItems;
};