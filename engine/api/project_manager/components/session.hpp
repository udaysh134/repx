#pragma once

#include <filesystem>
#include <variant>
#include <optional>

#include "extlibs.hpp"
#include "aliases.hpp"

#include "standard.hpp"
#include "ledger.hpp"


#define FRIEND_CLASSES_SESSION \
    friend class Base;


class Base;

struct Session {
    public:
        using Path = std::filesystem::path;
        using History = Json;
        using Runtime = std::variant<
            StandardRuntime,
            LedgerRuntime
        >;

        struct Auth {
            public:
                void authenticate(const Context::Standard::Session_Authenticate& ctx);
                void authenticate(const Context::Ledger::Session_Authenticate& ctx);

                void unauthenticate();

                bool isAuthenticated() const;
                std::optional<userID_t> getAuthUser() const;

            private:
                template <typename Context>
                void DISPATCH_authenticate(const Context &ctx);
        };
        

    private:
        Path path;
        History history;
        Runtime runtime;
        Auth auth;

        FRIEND_CLASSES_SESSION
};