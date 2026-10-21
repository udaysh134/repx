#pragma once

#include <string>
#include <variant>

#include "aliases.hpp"


#define FRIEND_CLASSES \
    friend class RepX;


class RepX;

class StandardEntry final {
    StandardEntry() = delete;

    private:
        FRIEND_CLASSES

        struct Genesis {
            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    schema_t _04_schema;
                    std::string _05_engine;
                    std::string _06_mode;
                    struct Project {
                        std::string name;
                        std::string description;
                    } _07_project;
                    struct Owner {
                        userID_t _01_uid;
                        std::string _02_name;
                        struct Auth {
                            salt_t _01_salt;
                            hash_t _02_hash;
                        } _03_auth;
                    } _08_owner;
                };
        };

    
    public:
        struct SubjectCreate {
            public:
                std::string _01_name;
                std::string _02_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_uid;
                    std::string _05_name;
                    std::string _06_reason;
                    userID_t _07_author;
                };
        };

        struct SubjectDeactivate {
            public:
                userID_t _01_target;
                std::string _02_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_reason;
                    userID_t _06_author;
                };
        };

        struct SubjectReactivate {
            public:
                userID_t _01_target;
                std::string _02_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_reason;
                    userID_t _06_author;
                };
        };

        struct Rep {
            public:
                userID_t _01_target;
                delta_t _02_delta;
                std::string _03_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    delta_t _05_delta;
                    std::string _06_reason;
                    userID_t _07_author;
                };
        };

        struct AdminAssign {
            public:
                std::string _01_name;
                salt_t _02_salt;
                hash_t _03_hash;
                std::string _04_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    struct Admin {
                        userID_t _01_uid;
                        std::string _02_name;
                        struct Auth {
                            salt_t _01_salt;
                            hash_t _02_hash;
                        } _03_auth;
                    } _04_admin;
                    std::string _05_reason;
                    userID_t _06_author;
                };
        };

        struct AdminRevoke {
            public:
                userID_t _01_target;
                std::string _02_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_reason;
                    userID_t _06_author;
                };
        };

        struct AdminRestore {
            public:
                userID_t _01_target;
                std::string _02_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_reason;
                    userID_t _06_author;
                };
        };

        struct UserRename {
            public:
                userID_t _01_target;
                std::string _02_name;
                std::string _03_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_name;
                    std::string _06_reason;
                    userID_t _07_author;
                };
        };

        struct ChangePass {
            public:
                userID_t _01_target;
                salt_t _02_salt;
                hash_t _03_hash;
                std::string _04_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    struct Auth {
                        salt_t _01_salt;
                        hash_t _02_hash;
                    } _05_auth;
                    std::string _06_reason;
                    userID_t _07_author;
                };
        };

        struct ProjectUpdate {
            public:
                std::string _01_name;
                std::string _02_description;
                std::string _03_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    struct Project {
                        std::string _01_name;
                        std::string _02_description;
                    } _04_project;
                    std::string _05_reason;
                    userID_t _06_author;
                };
        };

        struct ConfigUpdate {
            public:
                struct Config {
                    // Empty intentionally, data fields unknown
                } _01_config;
                std::string _02_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    struct Config {
                        // Empty intentionally, data fields unknown
                    } _04_config;
                    std::string _05_reason;
                    userID_t _06_author;
                };
        };

        struct Archive {
            public:
                std::string _01_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    std::string _04_reason;
                    userID_t _05_author;
                };
        };

        struct Unarchive {
            public:
                std::string _01_reason;

            private:
                FRIEND_CLASSES

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    std::string _04_reason;
                    userID_t _05_author;
                };
        };


    public:
        using Variants = std::variant<
            Genesis,
            SubjectCreate,
            SubjectDeactivate,
            SubjectReactivate,
            Rep,
            AdminAssign,
            AdminRevoke,
            AdminRestore,
            UserRename,
            ChangePass,
            ProjectUpdate,
            ConfigUpdate,
            Archive,
            Unarchive
        >;
};