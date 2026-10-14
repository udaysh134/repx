#pragma once

#include "session.hpp"

#include "update.hpp"
#include "info.hpp"
#include "entries.hpp"
#include "user.hpp"


class Project {
    public:
        Info info;

        User user;
        
        Entries entries;

        // archive();
        // unarchive();

        const Session::Path& path() const;
        const Session::History& history() const;
        const Session::Runtime& runtime() const;
        Session::Auth& auth() const;

    private:
        Session session;
};