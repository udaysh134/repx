#pragma once

#include "standard.hpp"
#include "ledger.hpp"


class CredentialManager {    
    public:
        auto create(const Context::Standard::Credential_Create& ctx);
        auto create(const Context::Ledger::Credential_Create& ctx);

        bool authenticate(const Context::Standard::Credential_Authenticate& ctx);
        bool authenticate(const Context::Ledger::Credential_Authenticate& ctx);

    private:
        template <typename Context>
        auto DISPATCH_create(const Context& ctx);

        template <typename Context>
        bool DISPATCH_authenticate(const Context& ctx);
};