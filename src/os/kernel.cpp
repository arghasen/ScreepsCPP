#include "kernel.hpp"

#include <Screeps/JSON.hpp>
#include <Screeps/Memory.hpp>

#include <iostream>

void slowdeath::os::Kernel::init()
{
    std::cout << "Kernel initialization" << std::endl;

    if (Screeps::Memory.value()["os"].isUndefined())
    {
        std::cout << "Memory is unallocated for os" << std::endl;
        Screeps::Memory.set("os", JSON::value_t::object); // creates an empty memory segment.
    }
}
