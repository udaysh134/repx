#pragma once

#include <string_view>

#include "project_manager.hpp"
#include "credential_manager.hpp"


class RepX {
    public:
        ProjectManager project;
        CredentialManager credential;
};

namespace Mode {
    inline constexpr std::string_view Standard = "standard";
    inline constexpr std::string_view Ledger = "ledger";
}