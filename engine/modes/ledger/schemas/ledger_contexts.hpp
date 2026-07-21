#pragma once

#include <string>

#include "aliases.hpp"
#include "resolver.hpp"


class Ledger;

namespace LedgerContext {
    struct Project_Create : Resolver<Ledger> {
        std::string _01_project_name;
        std::string _02_project_description;
        std::string _03_owner_name;
    };

    struct Credential_Create : Resolver<Ledger> {};

    struct Credential_Authenticate : Resolver<Ledger> {
        keyPair_t _01_public_key;
        keyPair_t _02_private_key;
    };
}