#pragma once

#include <string>

#include "aliases.hpp"
#include "session.hpp"
#include "ledger_contexts.hpp"

namespace Ctx = LedgerContext;


class RepX;

class Ledger {
    private:
        struct Project {
            Session create(const Ctx::Project_Create& ctx);
        };

        struct Credential {
            struct Data {
                keyPair_t public_key;
                keyPair_t private_key;
            };
        
            Data create(const Ctx::Credential_Create& ctx);
            bool authenticate(const Ctx::Credential_Authenticate& ctx);
        };

    private:
        Project project;
        Credential credential;

        friend class RepX;
};