#pragma once

#include <string_view>

#include "constants.hpp"

#include "standard.hpp"
#include "ledger.hpp"


using Mode = ::ModeID;

namespace Context {
    namespace Standard = ::StandardContext;
    namespace Ledger = ::LedgerContext;
}

namespace Entry {
    using Standard = ::StandardEntry;
    using Ledger = ::LedgerEntry;
}


#include "project.hpp"
#include "credential.hpp"


class RepX {
    public:
        Project project;
        Credential credential;
};