#pragma once

namespace slowdeath
{
    class Bootloader
    {
    public:
        Bootloader();
        ~Bootloader();
        Bootloader(const Bootloader &s) = delete;
        Bootloader &operator=(const Bootloader &s) = delete;
        Bootloader(Bootloader &&s) = delete;

        void run();

    private:
        Kernel kernel;
        Scheduler scheduler;
    };
}
