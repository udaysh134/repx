#pragma once

#include <string>

#include "aliases.hpp"
#include "session.hpp"
#include "ledger_contexts.hpp"


#define FRIEND_CLASSES \
    friend class RepX; \
    friend class ProjectManager;

namespace Ctx = LedgerContext;


class RepX;
class ProjectManager;


class Ledger {
    private:
        struct L_ProjectManager {
            Session create(const Ctx::Project_Create& ctx);
            Session open(const path_t& path);
        };

        struct L_CredentialManager {
            struct Data {
                keyPair_t public_key;
                keyPair_t private_key;
            };
        
            Data create(const Ctx::Credential_Create& ctx);
            bool verify(const Ctx::Credential_Verify& ctx);
        };

        struct L_Project {

        };

    private:
        L_ProjectManager project;
        L_CredentialManager credential;

        FRIEND_CLASSES
};