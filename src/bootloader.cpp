#include "bootloader.hpp"

#include <Screeps/Context.hpp>
#include <Screeps/Creep.hpp>

#include <iostream>

slowdeath::Bootloader::Bootloader()
{
    Screeps::Context::update();
    std::cout << "hi hi !!!" << Screeps::Game.cpuGetUsed() << std::endl;
}

slowdeath::Bootloader::~Bootloader()
{
    std::cout << "End of tick:" << Screeps::Game.cpuGetUsed() << std::endl;
}

void slowdeath::Bootloader::run()
{
    std::cout << "Launching Operating System" << std::endl;
    kernel.init();
}