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

        /**
         * process the jobs and creates a schedule for them to run
         */
        void schedule();

        int getTotalJobs();

        /**
         * process all the jobs and creates a schedule for them to run, including ones that are sleeping, waiting or ran last tick.
         */
        void reschedule();

        /**
         * get the next pid to run
         * @return a valid pid if there is a process to run or NO_PID if there is no process to run
         */
        PId getNextPid();

        /**
         * get the process for the given pid
         * @param i
         * @return
         */
        Process* getProcessForPid(PId i);

        uint16_t getProcessCount();

        uint16_t getCompletedProcessCount();
    };
} // namespace os
} // namespace slowdeath