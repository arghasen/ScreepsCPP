#include "bootloader.hpp"

#include <Screeps/Context.hpp>
#include <Screeps/Creep.hpp>

slowdeath::Bootloader::Bootloader()
{
    Screeps::Context::update();
    setEpoch();
    setOSVersion();
    JS::console.log(std::string("hi hi !!!"), Screeps::Game.cpuGetUsed());
}

void slowdeath::Bootloader::setOSVersion() const {
    if(Screeps::Memory["version"].empty())
    {
        Screeps::Memory.set("epoch", JSON(version));
    }
}

void slowdeath::Bootloader::setEpoch() const {
    if(Screeps::Memory["epoch"].empty())
    {
        Screeps::Memory.set("epoch", JSON(Screeps::Game.time()));
    }
}

slowdeath::Bootloader::~Bootloader()
{
    std::string a = "End of Tick:";
    JS::console.log(a, Screeps::Game.cpuGetUsed());
}

void slowdeath::Bootloader::run()
{
    JS::console.log(std::string("Launching Operating System"));
    kernel.init();
    kernel.run();
    kernel.shutdown();
}