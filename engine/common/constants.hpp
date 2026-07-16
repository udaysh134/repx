#pragma once

#include <string_view>

#include "repx.hpp"


namespace EngineConstant {
    namespace ModeName {
        inline constexpr std::string_view Standard = Mode::Standard;
        inline constexpr std::string_view Ledger = Mode::Ledger;
    }
}