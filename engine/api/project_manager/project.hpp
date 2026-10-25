#pragma once

#include <variant>

#include "aliases.hpp"
#include "constants.hpp"

#include "standard.hpp"
#include "ledger.hpp"


class Project {
    public:
        ModeID detectMode(const path_t& path);

        StandardBase create(const Context::Standard::Project_Create& ctx);
        LedgerBase create(const Context::Ledger::Project_Create& ctx);

        StandardBase open(const Context::Standard::Project_Open& ctx);
        LedgerBase open(const Context::Ledger::Project_Open& ctx);
    
    private:
        template <typename Context>
        auto DISPATCH_create(const Context& ctx);

        template <typename Context>
        auto DISPATCH_open(const Context& ctx);
};