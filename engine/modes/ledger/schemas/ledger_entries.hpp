#pragma once

#include <string>
#include <variant>

#include "aliases.hpp"


class RepX;

namespace LedgerEntry {
    struct Genesis {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        schema_t schema;
        std::string engine;
        std::string mode;
        struct Project {
            std::string name;
            std::string description;
        } project;
        struct Owner {
            userID_t uid;
            std::string name;
            keyPair_t pubKey;
        } owner;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct SubjectCreate {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t uid;
        std::string name;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct SubjectDeactivate {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t target;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct SubjectReactivate {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t target;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct Rep {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t target;
        delta_t delta;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct AdminAssign {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        struct Admin {
            userID_t uid;
            std::string name;
            keyPair_t pubKey;
        } admin;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct AdminRevoke {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t target;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct AdminRestore {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t target;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct UserRename {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t target;
        std::string name;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct RotateKey {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t target;
        keyPair_t key;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct ProjectUpdate {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        struct Project {
            std::string name;
            std::string description;
        } project;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct ConfigUpdate {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        struct Config {
            // Empty intentionally, data fields unknown
        } config;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct Tail {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct Archive {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
    
    struct Unarchive {
        entryID_t id;
        timeMS_t timestamp;
        std::string type;
        std::string reason;
        userID_t author;
        hash_t prevHash;
        hash_t hash;
        sig_t sig;
    };
}

using LedgerEntriesVariant = std::variant<
    LedgerEntry::Genesis,
    LedgerEntry::SubjectCreate,
    LedgerEntry::SubjectDeactivate,
    LedgerEntry::SubjectReactivate,
    LedgerEntry::Rep,
    LedgerEntry::AdminAssign,
    LedgerEntry::AdminRevoke,
    LedgerEntry::AdminRestore,
    LedgerEntry::UserRename,
    LedgerEntry::RotateKey,
    LedgerEntry::ProjectUpdate,
    LedgerEntry::ConfigUpdate,
    LedgerEntry::Tail,
    LedgerEntry::Archive,
    LedgerEntry::Unarchive
>;