// Headers
#include "state.hpp"


/*
----------------------------------------------------------------------------------------------------
Normal Member Functions
----------------------------------------------------------------------------------------------------
*/
std::size_t State::index() const {
    return selectedIndex;
}

void State::moveUp(std::size_t itemCount) {
    if (itemCount == 0) return;
    if (selectedIndex > 0) --selectedIndex;
}

void State::moveDown(std::size_t itemCount) {
    if (itemCount == 0) return;
    if (selectedIndex < itemCount - 1) ++selectedIndex;
}

void State::reset() {
    selectedIndex = 0;
    editing = false;
    inputBuffer.clear();
    selectedItems.clear();
}


/*
----------------------------------------------------------------------------------------------------
Functions for INPUT Handling
----------------------------------------------------------------------------------------------------
*/
void State::startEditing() {
    editing = true;
}

void State::stopEditing() {
    editing = false;
}

bool State::isEditing() const {
    return editing;
}


void State::appendChar(char c) {
    if (editing) { inputBuffer.push_back(c); }
}

void State::removeChar() {
    if (editing && !inputBuffer.empty()) {
        inputBuffer.pop_back();
    }
}

const std::string& State::buffer() const {
    return inputBuffer;
}


/*
----------------------------------------------------------------------------------------------------
Functions for SELECTION buttons
----------------------------------------------------------------------------------------------------
*/
void State::toggleSelection(std::size_t itemIndex) {
    if (selectedItems.count(itemIndex)) {
        selectedItems.erase(itemIndex);
    } else {
        selectedItems.insert(itemIndex);
    }
}

bool State::isSelected(std::size_t itemIndex) const {
    return selectedItems.count(itemIndex) > 0;
}