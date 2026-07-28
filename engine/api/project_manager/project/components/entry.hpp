#pragma once


class Project;

struct Entry {
    private:
        // append();
        // discard_last();
        // discard_all();

        friend class Project;
    
    private:
        Project* _project;
};