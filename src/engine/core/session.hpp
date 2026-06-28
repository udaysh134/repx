#pragma once

#include <filesystem>
#include <variant>

#include "extlibs.hpp"
#include "standard/runtime.hpp"
#include "ledger/runtime.hpp"


struct Session {
    std::filesystem::path path;
    Json history;
    std::variant<
        StandardRuntime,
        LedgerRuntime
    > runtime;
};