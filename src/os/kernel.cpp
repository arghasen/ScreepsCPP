#include "kernel.hpp"

#include <Screeps/JSON.hpp>
#include <Screeps/Memory.hpp>
#include <string>

void slowdeath::os::Kernel::init()
{
    JS::console.log(std::string("Kernel Initalization"));

    if (Screeps::Memory.value()["os"].isUndefined())
    {
        JS::console.log(std::string("Memory is unallocated for os"));
        Screeps::Memory.set("os", JSON::value_t::object); // creates an empty memory segment.
    }

    scheduler.schedule();
}
