#pragma once

#include <filesystem>
#include <string_view>

#include "session.hpp"


class RepX {
    public:
        bool createProject(const std::filesystem::path& path);
        bool openProject(const std::filesystem::path& path);
        bool unlockProject();

    private:
        Session session;
};

namespace Mode {
    inline constexpr std::string_view Standard = "standard";
    inline constexpr std::string_view Ledger = "ledger";
}