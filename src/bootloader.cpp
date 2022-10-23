#include "bootloader.hpp"

#include <Screeps/Context.hpp>
constexpr auto versionKey="version";
constexpr auto epochKey ="epoch";

slowdeath::Bootloader::Bootloader()
{
    Screeps::Context::update();
    memory_ = JS::toJSON(Screeps::Memory.value());
    JS::console.log(std::string("hi hi !!!"), Screeps::Game.cpuGetUsed());
    setEpoch();
    setOSVersion();
}

void slowdeath::Bootloader::setOSVersion() const
{
    if (!isSet(versionKey)|| getVersion() !=version_) {
        Screeps::Memory.set(versionKey, JSON(version_));
    }
}
bool slowdeath::Bootloader::isSet(std::string key) const
{
    return memory_.contains(key);
}

std::string slowdeath::Bootloader::getVersion() const
{
    return memory_[versionKey].get<std::string>();
}

void slowdeath::Bootloader::setEpoch() const
{
    if (isSet(epochKey)) {
        Screeps::Memory.set(epochKey, JSON(Screeps::Game.time()));
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
    kernel_.init(memory_);
    kernel_.run();
    kernel_.shutdown();
}