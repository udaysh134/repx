#pragma once

#include <string>
#include <variant>

#include "aliases.hpp"


#define FRIEND_CLASSES_LEDGER_ENTRY \
    friend class RepX;


class RepX;

class LedgerEntry final {
    LedgerEntry() = delete;

    private:
        FRIEND_CLASSES_LEDGER_ENTRY

        struct Genesis {
            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    schema_t _04_schema;
                    std::string _05_engine;
                    std::string _06_mode;
                    struct Project {
                        std::string _01_name;
                        std::string _02_description;
                    } _07_project;
                    struct Owner {
                        userID_t _01_uid;
                        std::string _02_name;
                        keyPair_t _03_pubKey;
                    } _08_owner;
                    hash_t _09_prevHash;
                    hash_t _10_hash;
                    sig_t _11_sig;
                };
        };

        struct Tail {
            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_author;
                    hash_t _05_prevHash;
                    hash_t _06_hash;
                    sig_t _07_sig;
                };
        };

        
    public:
        struct SubjectCreate {
            public:
                std::string _01_name;
                std::string _02_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_uid;
                    std::string _05_name;
                    std::string _06_reason;
                    userID_t _07_author;
                    hash_t _08_prevHash;
                    hash_t _09_hash;
                    sig_t _10_sig;
                };
        };

        struct SubjectDeactivate {
            public:
                userID_t _01_target;
                std::string _02_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_reason;
                    userID_t _06_author;
                    hash_t _07_prevHash;
                    hash_t _08_hash;
                    sig_t _09_sig;
                };
        };

        struct SubjectReactivate {
            public:
                userID_t _01_target;
                std::string _02_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_reason;
                    userID_t _06_author;
                    hash_t _07_prevHash;
                    hash_t _08_hash;
                    sig_t _09_sig;
                };
        };

        struct Rep {
            public:
                userID_t _01_target;
                delta_t _02_delta;
                std::string _03_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    delta_t _05_delta;
                    std::string _06_reason;
                    userID_t _07_author;
                    hash_t _08_prevHash;
                    hash_t _09_hash;
                    sig_t _10_sig;
                };
        };

        struct AdminAssign {
            public:
                std::string _01_name;
                keyPair_t _02_pubKey;
                std::string _03_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    struct Admin {
                        userID_t _01_uid;
                        std::string _02_name;
                        keyPair_t _03_pubKey;
                    } _04_admin;
                    std::string _05_reason;
                    userID_t _06_author;
                    hash_t _07_prevHash;
                    hash_t _08_hash;
                    sig_t _09_sig;
                };
        };

        struct AdminRevoke {
            public:
                userID_t _01_target;
                std::string _02_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_reason;
                    userID_t _06_author;
                    hash_t _07_prevHash;
                    hash_t _08_hash;
                    sig_t _09_sig;
                };
        };

        struct AdminRestore {
            public:
                userID_t _01_target;
                std::string _02_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_reason;
                    userID_t _06_author;
                    hash_t _07_prevHash;
                    hash_t _08_hash;
                    sig_t _09_sig;
                };
        };

        struct UserRename {
            public:
                userID_t _01_target;
                std::string _02_name;
                std::string _03_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    std::string _05_name;
                    std::string _06_reason;
                    userID_t _07_author;
                    hash_t _08_prevHash;
                    hash_t _09_hash;
                    sig_t _10_sig;
                };
        };

        struct RotateKey {
            public:
                userID_t _01_target;
                keyPair_t _02_key;
                std::string _03_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    userID_t _04_target;
                    keyPair_t _05_key;
                    std::string _06_reason;
                    userID_t _07_author;
                    hash_t _08_prevHash;
                    hash_t _09_hash;
                    sig_t _10_sig;
                };
        };

        struct ProjectUpdate {
            public:
                std::string _01_name;
                std::string _02_description;
                std::string _03_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

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
                    hash_t _07_prevHash;
                    hash_t _08_hash;
                    sig_t _09_sig;
                };
        };

        struct ConfigUpdate {
            public:
                struct Config {
                    // Empty intentionally, data fields unknown
                } _01_config;
                std::string _02_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    struct Config {
                        // Empty intentionally, data fields unknown
                    } _04_config;
                    std::string _05_reason;
                    userID_t _06_author;
                    hash_t _07_prevHash;
                    hash_t _08_hash;
                    sig_t _09_sig;
                };
        };

        struct Archive {
            public:
                std::string _01_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    std::string _04_reason;
                    userID_t _05_author;
                    hash_t _06_prevHash;
                    hash_t _07_hash;
                    sig_t _08_sig;
                };
        };

        struct Unarchive {
            public:
                std::string _01_reason;

            private:
                FRIEND_CLASSES_LEDGER_ENTRY

                struct Internal {
                    entryID_t _01_id;
                    timeMS_t _02_timestamp;
                    std::string _03_type;
                    std::string _04_reason;
                    userID_t _05_author;
                    hash_t _06_prevHash;
                    hash_t _07_hash;
                    sig_t _08_sig;
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
            RotateKey,
            ProjectUpdate,
            ConfigUpdate,
            Tail,
            Archive,
            Unarchive
        >;
};