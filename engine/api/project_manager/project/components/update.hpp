#pragma once


class Project;

struct Update {
    private:
        // name();
        // description();

        friend class Project;
    
    private:
        Project* _project;
};