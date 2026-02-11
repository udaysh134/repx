// Headers
#include "options.hpp"
#include "navigation.hpp"


/*
----------------------------------------------------------------------------------------------------
Constructor Definition
----------------------------------------------------------------------------------------------------
*/
Options::Options() {
    pages[Navigation::PageId::HOME] = {
        {
            { "Create New",  Navigation::PageId::NEW },
            { "Open Existing", Navigation::PageId::OPEN },
            { "Settings", Navigation::PageId::SETTINGS },
            { "Exit", Navigation::PageId::EXIT }
        }
    };
}

/*
----------------------------------------------------------------------------------------------------
Member Function Definitions
----------------------------------------------------------------------------------------------------
*/
void Options::moveUp() {
    if (selectedIndex == 0) {
        selectedIndex = pages.begin()->second.pageItems.size() - 1;
    } else {
        selectedIndex--;
    }
}

void Options::moveDown() {
    auto size = pages.begin()->second.pageItems.size();

    if (selectedIndex >= size - 1) {
        selectedIndex = 0;
    } else {
        selectedIndex++;
    }
}

int Options::currentIndex() const {
    return selectedIndex;
}

const std::vector<Options::Item>& Options::currentItems(Navigation::PageId page) const {
    return pages.at(page).pageItems;
}

Navigation::PageId Options::activate(Navigation::PageId page) const {
    const auto& items = pages.at(page).pageItems;
    return items[selectedIndex].targetPage;
}