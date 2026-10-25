#pragma once

#include <string_view>


enum class ModeID {
    STANDARD,
    LEDGER
};

namespace ModeName {
    inline constexpr std::string_view Standard = "standard";
    inline constexpr std::string_view Ledger = "ledger";
}