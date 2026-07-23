#pragma once

#include <variant>

#include "project.hpp"
#include "aliases.hpp"


class ProjectManager {
    public:
        Project create(const Context::Standard::Project_Create& ctx);
        Project create(const Context::Ledger::Project_Create& ctx);

        Project open(const path_t& path);
    
    private:
        template <typename Context>
        Project DISPATCH_create(const Context& ctx);
};