#include "scheduler.hpp"

void slowdeath::os::Scheduler::schedule()
{
}

int slowdeath::os::Scheduler::getTotalJobs() {
    return 0;
}

void slowdeath::os::Scheduler::reschedule() {

}

slowdeath::os::PId slowdeath::os::Scheduler::getNextPid() {
    return NO_PID;
}

slowdeath::os::Process* slowdeath::os::Scheduler::getProcessForPid(slowdeath::os::PId i) {
    return nullptr;
}

uint16_t slowdeath::os::Scheduler::getProcessCount() {
    return 0;
}

uint16_t slowdeath::os::Scheduler::getCompletedProcessCount() {
    return 0;
}
