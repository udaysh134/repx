#pragma once

#include <string>
#include <variant>

#include "typealias.hpp"


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
        struct Auth {
            std::string salt;
            std::string hash;
        } auth;
    } owner;
};

struct SubjectCreate {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t uid;
    std::string name;
    std::string reason;
    userID_t author;
};

struct SubjectDeactivate {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string reason;
    userID_t author;
};

struct SubjectReactivate {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string reason;
    userID_t author;
};

struct Rep {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    delta_t delta;
    std::string reason;
    userID_t author;
};

struct AdminAssign {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    struct Admin {
        userID_t uid;
        std::string name;
        struct Auth {
            std::string salt;
            std::string hash;
        } auth;
    } admin;
    std::string reason;
    userID_t author;
};

struct AdminRevoke {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string reason;
    userID_t author;
};

struct AdminRestore {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string reason;
    userID_t author;
};

struct UserRename {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string name;
    std::string reason;
    userID_t author;
};

struct ChangePass {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    struct Auth {
        std::string salt;
        std::string hash;
    } auth;
    std::string reason;
    userID_t author;
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
};

struct Archive {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    std::string reason;
    userID_t author;
};

struct Unarchive {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    std::string reason;
    userID_t author;
};


using StandardEntriesVariant = std::variant<
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