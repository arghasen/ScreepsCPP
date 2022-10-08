#pragma once
#include "noncopyable.hpp"
#include "nonmoveable.hpp"

namespace slowdeath
{
    namespace utils
    {
        class NoCopyorMove : public NonCopyable, public NonMoveable
        {
            public:
            NoCopyorMove() = default;
            ~NoCopyorMove() override = default;
        };
    } // namespace utils
} // namespace slowdeath