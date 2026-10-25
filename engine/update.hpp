#pragma once


#define FRIEND_CLASSES_UPDATE \
    friend class Base;


class Base;

struct Update {
    private:
        // name();
        // description();

        FRIEND_CLASSES_UPDATE
    
    private:
        Base* base;
};