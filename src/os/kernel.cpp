#include "kernel.hpp"

#include <Screeps/Memory.hpp>
#include <string>

constexpr auto key_os="os";
constexpr auto key_scheduler = "scheduler";
void slowdeath::os::Kernel::init(JSON memory)
{
    JS::console.log(JS::Value("Kernel Initalization"));
    memory_ = std::move(memory);
    JS::console.log(std::string("memory:"), memory_.dump());
    initializeMemory();
    scheduler_.init(memory_[key_os][key_scheduler]);
    scheduler_.schedule();
    if (scheduler_.getTotalJobs() == 0) {
        basicCreep();
    }
}

void slowdeath::os::Kernel::initializeMemory() const
{
    if (!memory_.contains("os")) {
        JS::console.log(std::string("Memory is unallocated for os"));

        JSON j;
        j[key_scheduler] = scheduler_.initializeMemory();

        Screeps::Memory.set(key_os, j);
        Screeps::Memory.set("stats", JSON::object());
    }
}

void slowdeath::os::Kernel::run()
{
    scheduler_.reschedule();
    while (canContinueRunning()) {
        auto currentProcessPid = scheduler_.getNextPid();
        if (currentProcessPid == os::NO_PID) {
            JS::console.log(std::string("suspending kernel as no PId left to run"));
            return;
        } else {
            runProcess(currentProcessPid);
        }
    }
}

void slowdeath::os::Kernel::runProcess(slowdeath::os::PId currentProcessPid)
{
    JS::console.log(std::string("Kernel: running pid: "), currentProcessPid);
    auto process = scheduler_.getProcessForPid(currentProcessPid);
    try {
        process->main();
    }
    catch (std::exception &e) {
        JS::console.log(std::string("errorType:") + e.what());
    }
}

void slowdeath::os::Kernel::shutdown()
{
    auto processCount = scheduler_.getProcessCount();
    auto completedCount = scheduler_.getCompletedProcessCount();
    Screeps::Memory.set("scheduler", scheduler_.getMemory());
    JS::console.log(std::string("Processes Run format: "), completedCount, processCount);
    cleanupMemory();
    //Screeps::Memory.set()
}

bool slowdeath::os::Kernel::canContinueRunning()
{
    return true;
}

void slowdeath::os::Kernel::cleanupMemory()
{

}
