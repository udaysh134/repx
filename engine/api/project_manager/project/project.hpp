#pragma once

#include "session.hpp"

#include "update.hpp"
#include "info.hpp"
#include "entries.hpp"
#include "user.hpp"


class Project {
    public:
        Info info;

        Entries entries;
        
        User user;

        // archive();
        // unarchive();

        // subject_create();
        // subject_deactivate();
        // subject_reactivate();

        const Session::Path& path() const;
        const Session::History& history() const;
        const Session::Runtime& runtime() const;
        Session::Auth& auth() const;

    private:
        Session session;
};