#pragma once
#include <map>
namespace slowdeath {
namespace os {

//class ProcessFactory{
//    template<typename T>
//    static T* createor(Args... args){
//        return new T(args...);
//    }
//};
class Creator;
class ProcessRegistry {
    std::map<std::string, Creator> registry;
};

} // os
} // slowdeath
