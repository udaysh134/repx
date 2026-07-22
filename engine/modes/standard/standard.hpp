#pragma once

#include <string>

#include "aliases.hpp"
#include "session.hpp"
#include "standard_contexts.hpp"

namespace Ctx = StandardContext;


class RepX;

class Standard {
    private:
        struct Project {
            Session create(const Ctx::Project_Create& ctx);
            Session open(const path_t& path);
        };

        struct Credential {
            struct Data {
                std::string password;
                salt_t salt;
                hash_t hash;
            };
        
            Data create(const Ctx::Credential_Create& ctx);
            bool authenticate(const Ctx::Credential_Authenticate& ctx);
        };

    private:
        Project project;
        Credential credential;

        friend class RepX;
};