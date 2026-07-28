#pragma once

#include "session.hpp"

#include "update.hpp"
#include "info.hpp"
#include "entry.hpp"
#include "user.hpp"


class Project {
    public:
        Update update;
        Info info;
        
        Entry entry;
        User user;

        const Session::Path& path() const;
        const Session::History& history() const;
        const Session::Runtime& runtime() const;

        // archive();
        // unarchive();

    private:
        Session session;
};