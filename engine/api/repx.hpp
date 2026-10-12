#pragma once

#include <string_view>

#include "project_manager.hpp"
#include "credential_manager.hpp"

#include "standard_contexts.hpp"
#include "ledger_contexts.hpp"

#include "standard_entries.hpp"
#include "ledger_entries.hpp"


class RepX {
    public:
        ProjectManager project;
        CredentialManager credential;
};

namespace Mode {
    inline constexpr std::string_view Standard = "standard";
    inline constexpr std::string_view Ledger = "ledger";
}

namespace Context {
    namespace Standard = ::StandardContext;
    namespace Ledger = ::LedgerContext;
}

namespace Entry {
    using Standard = ::StandardEntry;
    using Ledger = ::LedgerEntry;
}