#pragma once

#include <string>

#include "aliases.hpp"
#include "session.hpp"
#include "standard_contexts.hpp"


#define FRIEND_CLASSES \
    friend class RepX; \
    friend class ProjectManager;

namespace Ctx = StandardContext;


class RepX;
class ProjectManager;


class Standard {
    private:
        struct S_ProjectManager {
            Session create(const Ctx::Project_Create& ctx);
            Session open(const path_t& path);
        };

        struct S_CredentialManager {
            struct Data {
                std::string password;
                salt_t salt;
                hash_t hash;
            };
        
            Data create(const Ctx::Credential_Create& ctx);
            bool verify(const Ctx::Credential_Verify& ctx);
        };

        struct S_Project {
            
        };

    private:
        ProjectManager project;
        CredentialManager credential;

        FRIEND_CLASSES
};