#pragma once

#include "../utils/nocopyormove.hpp"
#include "process.hpp"

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

        void reschedule();

        PId getNextPid();

        Process* getProcessForPid(PId i);
    };
} // namespace os
} // namespace slowdeath