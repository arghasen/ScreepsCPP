#pragma once

#include <cstdint>
#include <limits>
#include <string>
#include "../utils/noncopyable.hpp"

namespace slowdeath {
    namespace os {
        using PId = uint16_t;
        constexpr auto NO_PID = std::numeric_limits<PId>::max();

        /**
         * Process is the base of all the runnable jobs in the OS.
         * Its must to inherit from Process in order for the kernel to run the jobs
         */
        class Process : public utils::NonCopyable {
        public:
            Process() = default;

            ~Process() = default;

            virtual void init();

            virtual int main() = 0;

            virtual void shutdown();

            std::string name;
        };
    } // namespace os
} // namespace slowdeath
