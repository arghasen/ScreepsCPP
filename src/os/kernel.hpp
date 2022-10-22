#pragma once

#include "../utils/nocopyormove.hpp"
#include "../usr/basic_bot.hpp"
#include "scheduler.hpp"


namespace slowdeath{
namespace os
{
    /**
     * Kernel holds the OS together and is responsible for its functioning
     */
class Kernel : public utils::NoCopyorMove
    {
        public:
        Kernel() = default;
        ~Kernel() override = default;
        /**
         * Initialization routing of the kernel
         * @param memory JSON object representing the memory of previous tick
         */
        void init(JSON memory);
        /**
         * The run routine ensures the whole system runs correctly
         */
        void run();

        /**
         * Cleanup and prepare for next tick
         */
        void shutdown();
    private:
        Scheduler scheduler;
        JSON memory_;

        bool canContinueRunning();

        void initializeMemory() const;

        void runProcess(unsigned short currentProcessPid);

    void cleanupMemory();
};
} // namespace os
} // namespace slowdeath