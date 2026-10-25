#pragma once


#define FRIEND_CLASSES \
    friend class Base;


class Base;

struct Entries {
    private:
        // append();
        // pop();
        // save();
        // discard();

        FRIEND_CLASSES
    
    private:
        Base* base;
};