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