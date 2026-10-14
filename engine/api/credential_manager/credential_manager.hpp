#pragma once

#include "standard.hpp"
#include "ledger.hpp"


class CredentialManager {    
    public:
        auto create(const Context::Standard::Credential_Create& ctx);
        auto create(const Context::Ledger::Credential_Create& ctx);

        bool verify(const Context::Standard::Credential_Verify& ctx);
        bool verify(const Context::Ledger::Credential_Verify& ctx);

    private:
        template <typename Context>
        auto DISPATCH_create(const Context& ctx);

        template <typename Context>
        bool DISPATCH_verify(const Context& ctx);
};