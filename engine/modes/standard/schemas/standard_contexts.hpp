#pragma once

#include <string>

#include "aliases.hpp"
#include "resolver.hpp"


class Standard;

namespace StandardContext {
    struct Project_Create : Resolver<Standard> {
        std::string _01_project_name;
        std::string _02_project_description;
        std::string _03_project_password;
        std::string _04_owner_name;
    };

    struct Credential_Create : Resolver<Standard> {
        std::string _01_password;
    };

    struct Credential_Authenticate : Resolver<Standard> {
        std::string _01_password;
        salt_t _02_salt;
        hash_t _03_hash;
    };
}