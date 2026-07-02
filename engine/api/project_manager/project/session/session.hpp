#pragma once

#include <filesystem>
#include <variant>

#include "extlibs.hpp"
#include "standard_runtime.hpp"
#include "ledger_runtime.hpp"


struct Session {
    std::filesystem::path path;
    Json history;
    std::variant<
        StandardRuntime,
        LedgerRuntime
    > runtime;
};