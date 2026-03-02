/**
 * @file state.hpp
 * @brief Runtime interaction state manager.
 *
 * Maintains navigation index, editing buffer,
 * and selection state for interactive options.
 */

#pragma once

#include <string>
#include <cstddef>
#include <unordered_set>


// ----------------------------------------------------------------------------------------------------
// State Class - Interaction Controller
// ----------------------------------------------------------------------------------------------------

/**
 * @brief Handles user interaction state.
 *
 * Tracks selected option index, editing mode,
 * input buffer, and multi-selection state.
 */
class State {
    public:
        // Navigation Index ---------------------------------------- >>

        /**
         * Retrieves the current set of selected index.
         *
         * @return Current selected option index.
         */
        std::size_t index() const;

        /**
         * Moves selection upwards.
         *
         * @param[in] itemCount Total number of selectable items.
         */
        void moveUp(std::size_t itemCount);

        /**
         * Moves selection downwards.
         *
         * @param[in] itemCount Total number of selectable items.
         */
        void moveDown(std::size_t itemCount);

        /**
         * Resets everything to default state.
         * Be careful in using this.
         */
        void reset();

        // Editing Mode ---------------------------------------- >>

        /**
         * Enables editing inside an input field.
         */
        void startEditing();

        /**
         * Disables editing from an input field.
         */
        void stopEditing();

        /**
         * Checks if currently in editing mode.
         *
         * @return TRUE if editing, otherwise FALSE.
         */
        bool isEditing() const;

        // Input Buffer ---------------------------------------- >>

        /**
         * Appends character to our custom input buffer. Enables input field system inside the program.
         *
         * @param[in] c Character to append.
         */
        void appendChar(char c);

        /**
         * Removes last character from the input buffer.
         */
        void removeChar();

        /**
         * Retrieves current input buffer.
         *
         * @return String of the saved input buffer of characters, but constant.
         */
        const std::string& buffer() const;

        // Selection Handling ---------------------------------------- >>

        /**
         * Toggles selection state of given item.
         *
         * @param[in] itemIndex Index of item.
         */
        void toggleSelection(std::size_t itemIndex);

        /**
         * Checks whether an item is selected.
         *
         * @param[in] itemIndex Index of item.
         * @return TRUE if selected, otherwise FALSE.
         */
        bool isSelected(std::size_t itemIndex) const;


    private:
        bool editing = false; ///< TRUE if in editing mode.

        std::size_t selectedIndex = 0; ///< Currently selected option index.
        std::string inputBuffer; ///< Stores user input while editing.

        std::unordered_set<std::size_t> selectedItems; ///< Stores indices of selected items.
};