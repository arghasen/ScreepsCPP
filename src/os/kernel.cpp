#include "kernel.hpp"

#include <Screeps/JSON.hpp>
#include <Screeps/Memory.hpp>
#include <string>

void slowdeath::os::Kernel::init() {
    JS::console.log(JS::Value("Kernel Initalization"));

    if (Screeps::Memory.value()["os"].isUndefined()) {
        JS::console.log(std::string("Memory is unallocated for os"));
        Screeps::Memory.set("os", JSON::object()); // creates an empty memory segment.
        Screeps::Memory.set("stats", JSON::object());
    }

    scheduler.schedule();
    if (scheduler.getTotalJobs() == 0) {
        basicCreep();
    }
}
void slowdeath::os::Kernel::run()
{
    scheduler.reschedule();
    while(canContinueRunning())
    {
        auto currentProcessPid = scheduler.getNextPid();
        if(currentProcessPid == os::NO_PID)
        {
            JS::console.log(std::string("suspending kernel as no PId left to run"));
            return;
        }
        else
        {
            JS::console.log(std::string("Kernel: running pid: "+ currentProcessPid));
            auto process = scheduler.getProcessForPid(currentProcessPid);
            try{
                process->main();
            }
            catch(std::exception& e)
            {
                JS::console.log(std::string ("errorType:")+e.what() );
            }
        }
    }

}

void slowdeath::os::Kernel::shutdown() {
    auto processCount = scheduler.getProcessCount();
    auto completedCount = scheduler.getCompletedProcessCount();
    JS::console.log(std::string("Processes Run:") + std::to_string(completedCount/processCount));
}

bool slowdeath::os::Kernel::canContinueRunning() {
    return true;
}
