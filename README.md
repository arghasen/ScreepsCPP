# ScreepsCPP
A screeps AI implementation in C++

This is a fresh write of the AI in C++ and WebAssembly. It is an experiment as of now and not a full fledged AI. 

## Dependencies:
- Screepsxx 
- googletest
- emsdk

### Notes

Read memory as a JS::Value. Converting and working with JSON is easier than JS::Value but is errorprone if the key doesnt exist.
```
    auto foo = Screeps::Memory.value()["foo"];
    std::cout << foo.as<int>() << std::endl;
```

## Operating Systems Coding
The AI is managed by an Operating System. For more information read OS style AI on screeps forum.

### Kernel
A basic kernel manages the system as a whole and runs as long as possible.

### Scheduler
FCFS based simple scheduler

### Process
Process is the base class of all runnable entities. Must have a main function.