#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class Timer
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        Timer();
        ~Timer();

        Timer(const Timer& InObj) = delete;
        Timer& operator=(const Timer& InObj) = delete;

        unsigned long long Reset();

        static unsigned long long GetTimestempForFps(const long long InFps);
        static unsigned long long GetTicksPerSecond();

    private:
        ImplementationPtr m_Implementation;
    };
}