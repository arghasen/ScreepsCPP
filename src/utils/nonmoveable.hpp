#pragma once

namespace slowdeath
{
    namespace utils
    {
        class NonMoveable
        {
            public:
            NonMoveable() =default;
            virtual ~NonMoveable() = default;
            NonMoveable(NonMoveable &&) = delete;
            NonMoveable &operator=(NonMoveable &&) = delete;
        };
    } // namespace utils
} // namespace slowdeath