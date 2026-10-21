#pragma once

#include <variant>

#include "project.hpp"
#include "aliases.hpp"

#include "standard.hpp"
#include "ledger.hpp"


class ProjectManager {
    public:
        Project create(const Context::Standard::Project_Create& ctx);
        Project create(const Context::Ledger::Project_Create& ctx);

        Standard::S_Project open(const Context::Standard::Project_Open& ctx);
        Ledger::L_Project open(const Context::Ledger::Project_Open& ctx);
    
    private:
        template <typename Context>
        Project DISPATCH_create(const Context& ctx);
};