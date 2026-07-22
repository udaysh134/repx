#pragma once

#include <variant>

#include "project.hpp"
#include "aliases.hpp"

using ProjectContext = std::variant<
    Context::Standard::Project_Create,
    Context::Ledger::Project_Create
>;


class ProjectManager {
    public:
        Project create(const ProjectContext& ctx);
        Project open(const path_t& path);
};