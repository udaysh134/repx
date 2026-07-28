#pragma once

#include <string>


class Project;

struct Info {
    private:
        std::string name() const;
        std::string description() const;
        std::string owner() const;
        std::string mode() const;

        friend class Project;
    
    private:
        Project* _project;
};