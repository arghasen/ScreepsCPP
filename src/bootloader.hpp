#pragma once
#include "utils/nocopyormove.hpp"

#include "os/kernel.hpp"

namespace slowdeath
{
    class Bootloader :public utils::NoCopyorMove
    {
    public:
        Bootloader();
        ~Bootloader() override;

        void run();

    private:
        os::Kernel kernel;
    };
}
