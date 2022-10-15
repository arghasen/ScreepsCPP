#pragma once

#include "../utils/nocopyormove.hpp"
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
        void init();
        void run();
        void shutdown();
    private:
        Scheduler scheduler;

        void basicCreep() const;

        bool canContinueRunning();
    };
} // namespace os
} // namespace slowdeath