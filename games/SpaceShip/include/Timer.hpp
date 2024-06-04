#pragma once

#include "Configs.hpp"

namespace SpaceShipGame
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

        long long Reset();

        static long long GetTimestempForFps(const long long InFps);
        static long long GetTicksPerSecond();

    private:
        ImplementationPtr m_Implementation;
    };
}