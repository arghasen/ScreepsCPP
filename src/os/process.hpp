#pragma once

#include <cstdint>
#include <limits>
#include <string>
#include "../utils/noncopyable.hpp"
#include <Screeps/JS.hpp>
#include <Screeps/JSON.hpp>

namespace slowdeath::os
{
using PId = uint16_t;
using ProcessData = JSON;
constexpr auto NO_PID = std::numeric_limits<PId>::max();

/**
 * Process is the base of all the runnable jobs in the OS.
 * Its must to inherit from Process in order for the kernel to run the jobs
 */
class Process : public utils::NonCopyable
{
public:
    Process(PId pid, std::string name, ProcessData data, Process *parent = nullptr);

    ~Process() override = default;

    explicit Process(PId pid);

    virtual void init();

    virtual int main() = 0;

    virtual void shutdown();
private:
    PId pid_;
    Process *parent_;
    ProcessData data_;
    std::string name_;
};
} // namespace slowdeath::os
