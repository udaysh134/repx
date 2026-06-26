#pragma once


struct StandardRuntime {
    "status": {
        "archived": [11, 12]
    },

    "session": {
        "locked": false,
        "uid": 1
    },


    "meta": {
        "schema": 1,
        "engine": "0.1.0",
        "mode": "standard",
        "project": {
            "name": "Project X",
            "description": "A scientific project to monitor lab assistants."
        },
        "owner": {
            "uid": 1,
            "name": "...",
            "auth": {
                "salt": "BASE64...",
                "hash": "abc123..."
            }
        },
        "settings": {},
        "createdAt": 1778936526728,
        "modifiedAt": 1778936529437
    },


    "signers": [
        {
            "uid": 1,
            "name": "user_001",
            "auth": {
                "salt": "BASE64...",
                "hash": "abc123..."
            },
            "role": "OWNER",
            "active": true,
            "actions": {
                "sysActs": [1, 2, 3, 5, 6, 11, 12],
                "datActs": [4, 7],
                "repsGiven": 8
            },
            "createdAt": 1778936526728,
            "modifiedAt": 1778936526728
        },
        {
            "uid": 2,
            "name": "user_002",
            "auth": {
                "salt": "BASE64...",
                "hash": "abc123..."
            },
            "role": "ADMIN",
            "active": true,
            "actions": {
                "sysActs": [8, 9, 10],
                "datActs": [13, 14, 15, 16],
                "repsGiven": 17
            },
            "createdAt": 1778936525314,
            "modifiedAt": 1778936525314
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
        },
        {
            "uid": 4,
            "name": "user_004",
            "rating": "B",
            "score": {
                "current": 8,
                "lowest": -2,
                "highest": 12
            },
            "active": true,
            "history": {
                "sys": [],
                "data": [1, 2, 4, 10]
            },
            "createdAt": 1778936525367,
            "modifiedAt": 1778936534829
        },
        {
            "uid": 5,
            "name": "user_005",
            "rating": "C",
            "score": {
                "current": 3,
                "lowest": -5,
                "highest": 4
            },
            "active": false,
            "history": {
                "sys": [9],
                "data": [6, 7, 11]
            },
            "createdAt": 17789365297816,
            "modifiedAt": 1778936539577
        }
    ],


    "stats": {
        "users": {
            "admins": {
                "activeAdmins": 2,
                "deadAdmins": 0
            },
            "subjects": {
                "activeSubs": 2,
                "deadSubs": 1
            }
        },
        "entries": {
            "sysEntries": 12,
            "datEntries": 37,
            "ownerEntries": 21,
            "adminEntries": 28
        },
        "totalReps": 25
    },


    "entries": []
};

extern StandardRuntime StandardRTS;