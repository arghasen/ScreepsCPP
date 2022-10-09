#pragma once

#include "../utils/noncopyable.hpp"

namespace slowdeath {
    namespace os {
        class Process : public utils::NonCopyable {
        public:
            Process() = default;

            ~Process() = default;

            virtual int main() = 0;
        private:

        };
    } // namespace os
} // namespace slowdeath
