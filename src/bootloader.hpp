#pragma once
#include "utils/nocopyormove.hpp"

#include "os/kernel.hpp"

namespace slowdeath
{
/**
 * A basic bootloader for starting and stopping the kernel.
 */
class Bootloader : public utils::NoCopyorMove
{
public:
    Bootloader();

    ~Bootloader() override;

    void run();

private:
    os::Kernel kernel;
    std::string version = "v1";
    JSON memory;

    void setEpoch() const;

    void setOSVersion() const;
};
}
