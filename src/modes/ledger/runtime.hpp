#pragma once

#include <vector>
#include <optional>
#include <string>
#include <cstdint>

#include "typeconvs.hpp"


struct SignersOBJ {
    userID_t uid;
    std::string name;
    std::string pubKey;
    std::string role;
    bool active;
    struct Actions {
        std::vector<entryID_t> sysActs;
        std::vector<entryID_t> datActs;
        reps_t repsGiven;
    } actions;
    timeMS_t createdAt;
    timeMS_t modifiedAt;
};


struct SubjectsOBJ {
    userID_t uid;
    std::string name;
    char rating;
    struct Score {
        score_t current;
        score_t lowest;
        score_t highest;
    } score;
    bool active;
    struct History {
        std::vector<entryID_t> sys;
        std::vector<entryID_t> data;
    } history;
    timeMS_t createdAt;
    timeMS_t modifiedAt;
};


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

    std::vector<SignersOBJ> signers;

    std::vector<SubjectsOBJ> subjects;

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
};

extern LedgerRuntime LedgerRTS;