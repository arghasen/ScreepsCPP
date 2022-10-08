#include <Screeps/Context.hpp>
#include <Screeps/Creep.hpp>

#include <emscripten.h>
#include <emscripten/bind.h>

EMSCRIPTEN_KEEPALIVE
extern "C" void loop()
{
	Screeps::Context::update();

	auto creeps = Screeps::Game.creeps();
	for (auto& creep : creeps)
		creep.second.say("hello little");
}

EMSCRIPTEN_BINDINGS(loop)
{
	emscripten::function("loop", &loop);
}
