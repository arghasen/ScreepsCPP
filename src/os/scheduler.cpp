#include "scheduler.hpp"

#include <Screeps/Memory.hpp>

constexpr auto key_processes ="processes";
constexpr auto key_ready = "ready";
constexpr auto key_running ="running";
constexpr auto key_completed = "completed";
constexpr auto key_waiting = "waiting";
constexpr auto key_count = "count";
constexpr auto key_sleeping = "sleeping";
constexpr auto key_index = "index";

void slowdeath::os::Scheduler::schedule()
{
}

int slowdeath::os::Scheduler::getTotalJobs()
{
    return 0;
}

void slowdeath::os::Scheduler::reschedule()
{

}

slowdeath::os::PId slowdeath::os::Scheduler::getNextPid()
{

    completeCurrentProcess();
    auto &readyQueue = memory_[key_processes][key_ready];
    if (readyQueue.empty()) {
        return NO_PID;
    }

    JS::console.log(memory_.dump());

    auto nextProcess = readyQueue.front();
    readyQueue.erase(readyQueue.begin());

    if (nextProcess) {
        memory_[key_processes][key_ready] = nextProcess;
        return nextProcess;
    }
    return NO_PID;
}

void slowdeath::os::Scheduler::completeCurrentProcess()
{
    auto currentProcess = getRunningProcess();
    if (currentProcess) {
        memory_[key_processes][key_completed].push_back(currentProcess);
        memory_[key_processes][key_completed] = false;
    }
}

slowdeath::os::PId slowdeath::os::Scheduler::getRunningProcess()
{ return memory_[key_processes][key_running]; }

slowdeath::os::Process *slowdeath::os::Scheduler::getProcessForPid(slowdeath::os::PId i)
{
    return nullptr;
}

uint16_t slowdeath::os::Scheduler::getProcessCount()
{
    return 0;
}

uint16_t slowdeath::os::Scheduler::getCompletedProcessCount()
{
    return 0;
}

void slowdeath::os::Scheduler::init(JSON memory)
{
    memory_ = std::move(memory);
}

JSON slowdeath::os::Scheduler::getMemory()
{
    return memory_;
}
JSON slowdeath::os::Scheduler::initializeMemory() const
{
    auto processes = JSON::object();
    processes[key_running] = false;
    processes[key_ready] = JSON::array();
    processes[key_sleeping] = JSON::array();
    processes[key_completed] = JSON::array();
    processes[key_waiting] = JSON::array();
    processes[key_count] = 0;
    processes[key_index] = JSON::object();
    auto scheduler = JSON::object();
    scheduler[key_processes] = processes;
    return scheduler;
}
