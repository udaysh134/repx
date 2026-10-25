#pragma once

#include <string>


#define FRIEND_CLASSES_INFO \
    friend class Base;


class Base;

struct Info {
    private:
        std::string name() const;
        std::string description() const;
        std::string owner() const;
        std::string mode() const;

        FRIEND_CLASSES_INFO
    
    private:
        Base* base;
};