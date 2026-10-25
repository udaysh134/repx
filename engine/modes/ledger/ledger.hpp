#pragma once

#include <string>

#include "aliases.hpp"

#include "ledger_base.hpp"
#include "ledger_constants.hpp"
#include "ledger_contexts.hpp"
#include "ledger_entries.hpp"
#include "ledger_runtime.hpp"


#define FRIEND_CLASSES_LEDGER \
    friend class RepX; \
    friend class Project; \
    friend class Credential;


class RepX;
class Project;
class Credential;

class Ledger {
    private:        
        struct LedgerProject {
            LedgerBase create(const LedgerContext::Project_Create& ctx);
            LedgerBase open(const path_t& path);
        };

        struct LedgerCredential {
            struct Data {
                keyPair_t public_key;
                keyPair_t private_key;
            };
        
            Data create(const LedgerContext::Credential_Create& ctx);
            bool verify(const LedgerContext::Credential_Verify& ctx);
        };

    private:
        LedgerProject project;
        LedgerCredential credential;

        FRIEND_CLASSES_LEDGER
};