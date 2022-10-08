#pragma once
#include "utils/nocopyormove.hpp"

#include "os/kernel.hpp"
#include "os/scheduler.hpp"

namespace slowdeath
{
    class Bootloader :public utils::NoCopyorMove
    {
    public:
        Bootloader();
        ~Bootloader() override;
        Bootloader(const Bootloader &s) = delete;
        Bootloader &operator=(const Bootloader &s) = delete;
        Bootloader(Bootloader &&s) = delete;

        void run();

    private:
        os::Kernel kernel;
        os::Scheduler scheduler;
    };
}
