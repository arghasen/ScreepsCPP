#include "scheduler.hpp"

#include <Screeps/Memory.hpp>

void slowdeath::os::Scheduler::schedule()
{
}

int slowdeath::os::Scheduler::getTotalJobs() {
    return 0;
}

void slowdeath::os::Scheduler::reschedule() {

}

slowdeath::os::PId slowdeath::os::Scheduler::getNextPid() {

    completeCurrentProcess();
    auto& readyQueue = memory_["processes"]["ready"];
    if (readyQueue.empty()) {
        return NO_PID;
    }

    JS::console.log(memory_.dump());

    auto nextProcess = readyQueue.front();
    readyQueue.erase(readyQueue.begin());

    if (nextProcess) {
        memory_["processes"]["running"] = nextProcess;
        return nextProcess;
    }
    return NO_PID;
}

void slowdeath::os::Scheduler::completeCurrentProcess() {
    auto currentProcess = getRunningProcess();
    if (currentProcess) {
        memory_["processes"]["completed"].push_back(currentProcess);
        memory_["processes"]["running"] = false;
    }
}

slowdeath::os::PId slowdeath::os::Scheduler::getRunningProcess() { return memory_["processes"]["running"]; }

slowdeath::os::Process* slowdeath::os::Scheduler::getProcessForPid(slowdeath::os::PId i) {
    return nullptr;
}

uint16_t slowdeath::os::Scheduler::getProcessCount() {
    return 0;
}

uint16_t slowdeath::os::Scheduler::getCompletedProcessCount() {
    return 0;
}

void slowdeath::os::Scheduler::init(JSON memory) {
    memory_ = std::move(memory);
}


JSON slowdeath::os::Scheduler::getMemory() {
    return memory_;
}