#pragma once

#include "../utils/nocopyormove.hpp"

namespace slowdeath{
namespace os
{
    class Kernel : public utils::NoCopyorMove
    {
        public:
        Kernel() = default;
        ~Kernel() override = default;
        void init();
    };
} // namespace os
} // namespace slowdeath