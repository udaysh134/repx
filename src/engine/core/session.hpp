#pragma once

#include <filesystem>

#include "extlibs.hpp"
#include "runtime.hpp"


struct Session {
    std::filesystem::path path;
    Json entries;
    Runtime runtime;
};