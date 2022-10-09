# ScreepsCPP
A screeps AI implementation in C++

This is a fresh write of the AI in C++ and WebAssembly. It is an experiment as of now and not a full fledged AI. 

## Dependencies:
- Screepsxx 
- googletest
- emsdk

###

Read memory as a JS::Value. Converting and working with JSON is easier than JS::Value but is errorprone if the key doesnt exist.
```
    auto foo = Screeps::Memory.value()["foo"];
    std::cout << foo.as<int>() << std::endl;
```