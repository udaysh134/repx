#pragma once

#include <vector>
#include <string>


class Navigation {
    public:
        enum class PageId {
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
            GEN_LB_CUSTOM,

            SETTINGS,
            EXIT,
        };

        struct PageContext {
            std::string pathLabel;
            std::string title;
            std::string message;
        };

        struct NavNode {
            PageId page;
            PageContext context;
        };

    public:
        Navigation();

        void enter(PageId page, PageContext context = {});
        void back();

        const NavNode& current() const;
        bool canGoBack() const;
        bool shouldExit() const;

    private:
        std::vector<NavNode> lineUp;
};