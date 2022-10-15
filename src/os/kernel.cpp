#include "kernel.hpp"

#include <Screeps/JSON.hpp>
#include <Screeps/Memory.hpp>
#include <Screeps/Game.hpp>
#include <Screeps/Creep.hpp>
#include <Screeps/StructureSpawn.hpp>
#include <Screeps/RoomPosition.hpp>
#include <Screeps/RoomObject.hpp>
#include <Screeps/Source.hpp>
#include <Screeps/StructureController.hpp>
#include <Screeps/Store.hpp>

#include <Screeps/Room.hpp>

#include <string>
#include <iostream>

void slowdeath::os::Kernel::init() {
    JS::console.log(JS::Value("Kernel Initalization"));

    if (Screeps::Memory.value()["os"].isUndefined()) {
        JS::console.log(std::string("Memory is unallocated for os"));
        Screeps::Memory.set("os", JSON::value_t::object); // creates an empty memory segment.
        Screeps::Memory.set("stats", JSON::value_t::object);
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
            JS::console.log(std::string("exiting kernel as no PId left to run"));
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
void slowdeath::os::Kernel::basicCreep() const {
    auto spawns = Screeps::Game.spawns();
    auto& sp1 = spawns.at("Spawn1");
    if(Screeps::Game.creeps().empty())
    {
        JS::console.log(std::string("creating a creep"));
        auto res = sp1.spawnCreep({Screeps::WORK,Screeps::CARRY, Screeps::MOVE}, "creep1");
        std::cout << "creep result: " << res << std::endl;
    }
    else
    {
        for(auto&& [k,c]:Screeps::Game.creeps())
        {
            JS::console.log(std::string("Creep:"),k, JS::toJSON(c).dump());
            c.say("Hello cpp");
            auto rm = Screeps::Game.rooms().at(c.pos().roomName());
            auto sources = rm.find(Screeps::FIND_SOURCES);
            auto& firstSource = sources[0];
            auto controller = rm.controller();
            auto m = c.memory();
            if(c.store().getUsedCapacity(Screeps::RESOURCE_ENERGY) ==0)
            {
                m["task"] = "harvest";
                c.setMemory(m);
            }
            if(c.store().getFreeCapacity(Screeps::RESOURCE_ENERGY) ==0)
            {
                m["task"] = "upgrade";
                c.setMemory(m);
            }
            if(m["task"] == "harvest" && c.harvest(*(dynamic_cast<Screeps::Source*>(firstSource.get())))==Screeps::ERR_NOT_IN_RANGE)
            {
                c.moveTo(*firstSource);
            }

            if(m["task"] == "upgrade" && c.upgradeController(*controller) == Screeps::ERR_NOT_IN_RANGE)
            {
                c.moveTo(*controller);
            }
        }
    }
}

bool slowdeath::os::Kernel::canContinueRunning() {
    return true;
}
