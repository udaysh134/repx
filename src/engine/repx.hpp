#pragma once

#include <filesystem>

class Session;

class RepX
{
public:
    // Project Lifecycle
    bool createProject(const std::filesystem::path& path);
    bool openProject(const std::filesystem::path& path);
    bool unlockProject();

private:
    Session* session = nullptr;
};