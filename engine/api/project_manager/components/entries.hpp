#pragma once


#define FRIEND_CLASSES_ENTRIES \
    friend class Base;


class Base;

struct Entries {
    private:
        // append();
        // pop();
        // save();
        // discard();

        FRIEND_CLASSES_ENTRIES
    
    private:
        Base* base;
};