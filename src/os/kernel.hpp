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
        void run();
    private:
        Scheduler scheduler;

        void basicCreep() const;

        bool canContinueRunning();
    };
} // namespace os
} // namespace slowdeath