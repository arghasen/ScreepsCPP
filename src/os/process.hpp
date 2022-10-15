#pragma once

#include <cstdint>
#include <limits>
#include <string>
#include "../utils/noncopyable.hpp"

namespace slowdeath {
    namespace os {
        using PId = uint16_t;
        constexpr auto NO_PID = std::numeric_limits<PId>::max();
        class Process : public utils::NonCopyable {
        public:
            Process() = default;

            ~Process() = default;

            virtual int main() = 0;

            std::string name;
        };
    } // namespace os
} // namespace slowdeath
