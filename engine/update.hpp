#pragma once


#define FRIEND_CLASSES \
    friend class Base;


class Base;

struct Update {
    private:
        // name();
        // description();

        FRIEND_CLASSES
    
    private:
        Base* base;
};