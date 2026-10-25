#pragma once

#include "standard.hpp"
#include "ledger.hpp"


class Credential {
    using StandardData = Standard::StandardCredential::Data;
    using LedgerData = Ledger::LedgerCredential::Data;

    public:
        StandardData create(const Context::Standard::Credential_Create& ctx);
        LedgerData create(const Context::Ledger::Credential_Create& ctx);

        bool verify(const Context::Standard::Credential_Verify& ctx);
        bool verify(const Context::Ledger::Credential_Verify& ctx);

    private:
        template <typename Context>
        auto DISPATCH_create(const Context& ctx);

        template <typename Context>
        bool DISPATCH_verify(const Context& ctx);
};