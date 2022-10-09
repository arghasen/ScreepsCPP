#pragma once

#include "../utils/nocopyormove.hpp"
#include "scheduler.hpp"


namespace slowdeath{
namespace os
{
    class Kernel : public utils::NoCopyorMove
    {
        public:
        Kernel() = default;
        ~Kernel() override = default;
        void init();

    private:
        Scheduler scheduler;
    };
} // namespace os
} // namespace slowdeath