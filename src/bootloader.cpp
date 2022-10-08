#include "bootloader.hpp"

#include <Screeps/Context.hpp>
#include <Screeps/Creep.hpp>

slowdeath::Bootloader::Bootloader()
{
    Screeps::Context::update();
    JS::console.log(std::string("hi hi !!!"), Screeps::Game.cpuGetUsed());
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
}