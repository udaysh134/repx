#pragma once

#include "entries.hpp"
#include "session.hpp"


struct Base {
    protected:
        virtual ~Base() = default;

    public:
        Entries entries;

        const Session::Path& path() const;
        const Session::History& history() const;
        const Session::Runtime& runtime() const;
        Session::Auth& auth() const;

    private:
        Session session;
};