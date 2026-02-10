#pragma once

#include <vector>

class Navigation {
    enum class pageId {
        HOME,

        BROWSE,
        ERROR,
        CONFIRMATION,

        NEW,
        OPEN,

        CONSOLE,
        ENTRIES,
        ENTRY_ADD,
        GEN_LB,

        GEN_LB_WEEKLY,
        GEN_LB_MONTHLY,
        GEN_LB_YEARLY,
        GEN_LB_SPECIFIC,

        SETTINGS,
        EXIT,
    } pgId;

    std::vector<pageId> path;


    void currentPage();
    void goTo();
    void goBack();
};