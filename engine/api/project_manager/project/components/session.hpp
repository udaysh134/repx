#pragma once

#include <filesystem>
#include <variant>

#include "extlibs.hpp"
#include "standard_runtime.hpp"
#include "ledger_runtime.hpp"


class Project;

struct Session {
    public:
        using Path = std::filesystem::path;
        using History = Json;
        using Runtime = std::variant<
            StandardRuntime,
            LedgerRuntime
        >;

    private:
        Path path;
        History history;
        Runtime runtime;

        friend class Project;
};