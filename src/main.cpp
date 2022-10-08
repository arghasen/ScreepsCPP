#include "bootloader.hpp"

#include <emscripten.h>
#include <emscripten/bind.h>

EMSCRIPTEN_KEEPALIVE
extern "C" void loop()
{
    slowdeath::Bootloader bl;
    bl.run();
}

EMSCRIPTEN_BINDINGS(loop)
{
    emscripten::function("loop", &loop);
}
