#pragma once

#include <string>

#include "typeconvs.hpp"


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
        std::string pubKey;
    } owner;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct SubjectCreate {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t uid;
    std::string name;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct SubjectDeactivate {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct SubjectReactivate {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct Rep {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    delta_t delta;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct AdminAssign {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    struct Admin {
        userID_t uid;
        std::string name;
        std::string pubKey;
    } admin;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct AdminRevoke {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct AdminRestore {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct UserRename {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string name;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct RotateKey {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t target;
    std::string key;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
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
    std::string prevHash;
    std::string hash;
    std::string sig;
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
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct Tail {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct Archive {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};


struct Unarchive {
    entryID_t id;
    timeMS_t timestamp;
    std::string type;
    std::string reason;
    userID_t author;
    std::string prevHash;
    std::string hash;
    std::string sig;
};