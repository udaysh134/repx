#pragma once

#include <string_view>

#include "constants.hpp"

#include "project.hpp"
#include "credential.hpp"

#include "standard.hpp"
#include "ledger.hpp"


using Mode = ::ModeID;

class RepX {
    public:
        Project project;
        Credential credential;
};

namespace Context {
    namespace Standard = ::StandardContext;
    namespace Ledger = ::LedgerContext;
}

namespace Entry {
    using Standard = ::StandardEntry;
    using Ledger = ::LedgerEntry;
}