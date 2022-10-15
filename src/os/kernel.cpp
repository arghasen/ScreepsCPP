#include "kernel.hpp"

#include <Screeps/JSON.hpp>
#include <Screeps/Memory.hpp>
#include <Screeps/Game.hpp>
#include <Screeps/Creep.hpp>
#include <Screeps/StructureSpawn.hpp>
#include <string>

void slowdeath::os::Kernel::init() {
    JS::console.log(std::string("Kernel Initalization"));

    if (Screeps::Memory.value()["os"].isUndefined()) {
        JS::console.log(std::string("Memory is unallocated for os"));
        Screeps::Memory.set("os", JSON::value_t::object); // creates an empty memory segment.
    }

    scheduler.schedule();
    if (scheduler.getTotalJobs() == 0) {
        auto spawns = Screeps::Game.spawns();
        auto& sp1 = spawns.at("spawn1");
        if(Screeps::Game.creeps().empty())
        {
            sp1.spawnCreep({"WORK","CARRY", "MOVE"}, "creep1");
        }

    }
}