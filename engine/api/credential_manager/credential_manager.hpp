#pragma once

#include "standard.hpp"
#include "ledger.hpp"

using StandardCred = Standard::Credential;
using LedgerCred = Ledger::Credential;


class CredentialManager {
    private:
        class Create :
            public StandardCred::Create,
            public LedgerCred::Create
        {};

        class Authenticate :
            public StandardCred::Authenticate,
            public LedgerCred::Authenticate
        {};

        
    public:
        Create create;
        Authenticate authenticate;
};