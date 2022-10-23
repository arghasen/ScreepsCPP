#pragma once

#include "utils/nocopyormove.hpp"
#include "os/kernel.hpp"

#include <Screeps/JS.hpp> // Review these inclusion
#include <Screeps/JSON.hpp>

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
    os::Kernel kernel_;
    std::string version_ = "2022.10.23";
    JSON memory_;

    void setEpoch() const;

    void setOSVersion() const;
    std::string getVersion() const;
    bool isSet(std::string key) const;
};
}
