#pragma once

#include "../utils/nocopyormove.hpp"
#include "process.hpp"

#include <Screeps/JS.hpp> // Review these inclusion
#include <Screeps/JSON.hpp>

namespace slowdeath
{
namespace os
{
// Reserved for future use with newer version of JSON lib
constexpr std::string_view processes = "processes";

constexpr std::string_view ready = "ready";
/**
 * An extremely basic scheduler, runs jobs in FCFS order.
 */
class Scheduler : public utils::NoCopyorMove
{
public:
    Scheduler() = default;
    ~Scheduler() override = default;

    /**
     * process the jobs and creates a schedule for them to run
     */
    void schedule();

    int getTotalJobs();

    /**
     * process all the jobs and creates a schedule for them to run, including ones that are sleeping, waiting or ran last tick.
     */
    void reschedule();

    /**
     * get the next pid to run
     * @return a valid pid if there is a process to run or NO_PID if there is no process to run
     */
    PId getNextPid();

    /**
     * get the process for the given pid
     * @param i
     * @return A pointer to the process
     */
    Process *getProcessForPid(PId i);

    /**
     * Gets the number of processes in the scheduler
     * @return the count
     */
    uint16_t getProcessCount();

    /**
     * Gets the number of completed processes since last reschedule
     * @return the count
     */
    uint16_t getCompletedProcessCount();

    /**
     * Initializes the scheduler with the memory contents.
     * @param memory JSON object holding the memory from previous run
     */
    void init(JSON memory);

    /**
     * Gets the current memory of the Scheduler to persist between ticks
     * @return JSON memory contents
     */
    JSON getMemory();

    /**
     * Launches a process
     * @param name process name
     * @param data process data(can be empty)
     * @param parent process parent(can be null)
     * @return Pid of the launched process
     */
    PId launch(std::string_view name, ProcessData data, Process *parent = nullptr);
    /**
     *
     * @return the JSON representation of the memory to initialize for scheduler
     */
    JSON initializeMemory() const;
private:
    JSON memory_;

    void completeCurrentProcess();

    PId getRunningProcess();
};
} // namespace os
} // namespace slowdeath