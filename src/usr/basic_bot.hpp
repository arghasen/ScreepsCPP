#ifndef SCREEPSAI_BASIC_BOT_HPP
#define SCREEPSAI_BASIC_BOT_HPP

#include <Screeps/Creep.hpp>
#include <Screeps/StructureSpawn.hpp>
#include <Screeps/RoomPosition.hpp>
#include <Screeps/RoomObject.hpp>
#include <Screeps/Source.hpp>
#include <Screeps/StructureController.hpp>
#include <Screeps/Store.hpp>
#include <Screeps/Room.hpp>
#include <Screeps/Game.hpp>

inline void basicCreep()  {
    auto spawns = Screeps::Game.spawns();
    auto& sp1 = spawns.at("Spawn1");
    if(Screeps::Game.creeps().empty())
    {
        auto res = sp1.spawnCreep({Screeps::WORK,Screeps::CARRY, Screeps::MOVE}, "creep1");
        JS::console.log(std::string("creating a creep: "), res );
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
#endif //SCREEPSAI_BASIC_BOT_HPP
