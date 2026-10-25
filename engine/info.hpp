#pragma once

#include <string>


#define FRIEND_CLASSES \
    friend class Base;


class Base;

struct Info {
    private:
        std::string name() const;
        std::string description() const;
        std::string owner() const;
        std::string mode() const;

        FRIEND_CLASSES
    
    private:
        Base* base;
};