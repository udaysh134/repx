#pragma once


class Project;

struct User {
    private:
        struct Owner {
            // transfer();
            // update_cred();
        };

        struct Admin {
            // assign();
            // revoke();
            // restore();
            // update_cred();
        };

        struct Subject {
            // create();
            // deactivate();
            // reactivate();
            // rep();
        };

    private:
        Owner owner;
        Admin admin;
        Subject subject;

        // rename();

        friend class Project;
    
    private:
        Project* _project;
};