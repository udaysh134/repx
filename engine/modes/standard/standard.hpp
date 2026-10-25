#pragma once

#include <string>

#include "aliases.hpp"
#include "session.hpp"

#include "standard_base.hpp"
#include "standard_constants.hpp"
#include "standard_contexts.hpp"
#include "standard_entries.hpp"
#include "standard_runtime.hpp"


#define FRIEND_CLASSES \
    friend class RepX; \
    friend class Project;


class RepX;
class Project;

class Standard {
    private:
        struct StandardProject {
            StandardBase create(const StandardContext::Project_Create& ctx);
            StandardBase open(const path_t& path);
        };

        struct StandardCredential {
            struct Data {
                std::string password;
                salt_t salt;
                hash_t hash;
            };
        
            Data create(const StandardContext::Credential_Create& ctx);
            bool verify(const StandardContext::Credential_Verify& ctx);
        };

    private:
        StandardProject project;
        StandardCredential credential;

        FRIEND_CLASSES
};