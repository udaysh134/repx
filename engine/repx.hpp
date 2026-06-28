#pragma once

#include <filesystem>

#include "session.hpp"


class RepX {
    public:
        bool createProject(const std::filesystem::path& path);
        bool openProject(const std::filesystem::path& path);
        bool unlockProject();

    private:
        Session session;
};