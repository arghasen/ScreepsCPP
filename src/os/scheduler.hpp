#pragma once

#include "../utils/nocopyormove.hpp"

namespace slowdeath{
namespace os
{
    class Scheduler :public utils::NoCopyorMove
    {
        public:
        Scheduler() = default;
        ~Scheduler() override = default;

        void schedule();

        int getTotalJobs();
    };
} // namespace os
} // namespace slowdeath