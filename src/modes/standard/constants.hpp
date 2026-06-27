#pragma once

#include <string_view>


namespace StandardConst {
    namespace Property {
        inline constexpr std::string_view MODE_NAME = "standard";
    }

    namespace Role {
        inline constexpr std::string_view OWNER = "OWNER";
        inline constexpr std::string_view ADMIN = "ADMIN";
    }

    namespace Rating {
        inline constexpr char A = 'A';
        inline constexpr char B = 'B';
        inline constexpr char C = 'C';
        inline constexpr char D = 'D';
    }
    
    namespace Entry {
        inline constexpr std::string_view GENESIS = "GENESIS";
        inline constexpr std::string_view SUBJECT_CREATE = "SUBJECT_CREATE";
        inline constexpr std::string_view SUBJECT_DEACTIVATE = "SUBJECT_DEACTIVATE";
        inline constexpr std::string_view SUBJECT_REACTIVATE = "SUBJECT_REACTIVATE";
        inline constexpr std::string_view REP = "REP";
        inline constexpr std::string_view ADMIN_ASSIGN = "ADMIN_ASSIGN";
        inline constexpr std::string_view ADMIN_REVOKE = "ADMIN_REVOKE";
        inline constexpr std::string_view ADMIN_RESTORE = "ADMIN_RESTORE";
        inline constexpr std::string_view USER_RENAME = "USER_RENAME";
        inline constexpr std::string_view CHANGE_PASS = "CHANGE_PASS";
        inline constexpr std::string_view PROJECT_UPDATE = "PROJECT_UPDATE";
        inline constexpr std::string_view CONFIG_UPDATE = "CONFIG_UPDATE";
        inline constexpr std::string_view ARCHIVE = "ARCHIVE";
        inline constexpr std::string_view UNARCHIVE = "UNARCHIVE";
    }
}