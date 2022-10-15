#pragma once

#include "../utils/nocopyormove.hpp"
#include "process.hpp"

namespace slowdeath{
namespace os
{
    /**
     * An extremely basic scheduler, runs jobs in FCFS order.
     */
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

        uint16_t getProcessCount();

        uint16_t getCompletedProcessCount();
    };
} // namespace os
} // namespace slowdeath