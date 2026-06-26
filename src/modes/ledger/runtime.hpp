#pragma once

#include <vector>
#include <optional>
#include <string>
#include <cstdint>

#include "typeconvs.hpp"


struct LedgerRuntime {
    struct Status {
        bool tampered;
        bool terminated;
        std::vector<entryID_t> archived;
    } status;

    struct Session {
        bool locked;
        std::optional<std::string> pubKey;
    } session;

    struct Meta {
        int schema;
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
        struct Settings {
            // Empty, as the schema itself is not yet decided
        } settings;
        timeMS_t createdAt;
        timeMS_t modifiedAt;
    } meta;

    std::vector<> signers;

    std::vector<> subjects;

    struct Stats {
        struct Users {
            struct Admins {
                count_t activeAdmins;
                count_t deadAdmins;
            } admins;
            struct Subjects {
                count_t activeSubs;
                count_t deadSubs;
            } subjects;
        } users;
        struct Entries {
            count_t sysEntries;
            count_t datEntries;
            count_t ownerEntries;
            count_t adminEntries;
        } entries;
        reps_t totalReps;
    } stats;

    std::vector<> entries;

    "signers": [
        {
            "uid": 1,
            "name": "user_001",
            "pubKey": "BASE64...",
            "role": "OWNER",
            "active": true,
            "actions": {
                "sysActs": [1, 2, 3, 5, 6, 11, 12],
                "datActs": [4, 7],
                "repsGiven": 8
            },
            "createdAt": 1778936526728,
            "modifiedAt": 1778936526728
        }
    ],


    "subjects": [
        {
            "uid": 3,
            "name": "user_003",
            "rating": "A",
            "score": {
                "current": 16,
                "lowest": 0,
                "highest": 21
            },
            "active": true,
            "history": {
                "sys": [8, 13],
                "data": [3, 5, 12, 14, 15, 16]
            },
            "createdAt": 1778936529011,
            "modifiedAt": 1778936543943
        }
    ],

    "entries": []
};

extern LedgerRuntime LedgerRTS;