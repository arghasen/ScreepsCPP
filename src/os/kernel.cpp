#include "kernel.hpp"

#include <Screeps/JSON.hpp>
#include <Screeps/Memory.hpp>
#include <string>

void slowdeath::os::Kernel::init(JSON memory)
{
    JS::console.log(JS::Value("Kernel Initalization"));
    memory_ = std::move(memory);
    JS::console.log(std::string("memory:"), memory_.dump());
    initializeMemory();
    scheduler.init(memory_["os"]["scheduler"]);
    scheduler.schedule();
    if (scheduler.getTotalJobs() == 0) {
        basicCreep();
    }
}

void slowdeath::os::Kernel::initializeMemory() const
{
    if (Screeps::Memory.isUndefined("os")) {
        JS::console.log(std::string("Memory is unallocated for os"));

        JSON processes = JSON::object();
        processes["running"] = false;
        processes["ready"] = JSON::array();
        processes["sleeping"] = JSON::array();
        processes["completed"] = JSON::array();
        processes["waiting"] = JSON::array();
        processes["count"] = 0;
        processes["index"] = JSON::object();

        JSON j;
        j["scheduler"] = JSON::object();
        j["scheduler"]["processes"] = processes;

        Screeps::Memory.set("os", j);
        Screeps::Memory.set("stats", JSON::object());
    }
}

void slowdeath::os::Kernel::run()
{
    scheduler.reschedule();
    while (canContinueRunning()) {
        auto currentProcessPid = scheduler.getNextPid();
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
    auto process = scheduler.getProcessForPid(currentProcessPid);
    try {
        process->main();
    }
    catch (std::exception &e) {
        JS::console.log(std::string("errorType:") + e.what());
    }
}

void slowdeath::os::Kernel::shutdown()
{
    auto processCount = scheduler.getProcessCount();
    auto completedCount = scheduler.getCompletedProcessCount();
    Screeps::Memory.set("scheduler", scheduler.getMemory());
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
