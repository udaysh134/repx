#pragma once


class Project;

struct Entries {
    private:
        // append();
        // pop();
        // save();
        // discard();

        friend class Project;
    
    private:
        Project* _project;
};