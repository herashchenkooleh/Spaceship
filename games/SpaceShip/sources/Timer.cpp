#include "Timer.hpp"
#include <chrono>
#include <optional>

namespace SpaceShipGame
{
    struct Timer::Implementation
    {
        std::optional<std::chrono::time_point<std::chrono::high_resolution_clock>> m_PrevTime;
    };

    Timer::Timer()
        : m_Implementation(MakeShared<Implementation>())
    {

    }

    Timer::~Timer() = default;

    long long Timer::Reset()
    {
        auto CurrentTime = std::chrono::high_resolution_clock::now();
        if (m_Implementation->m_PrevTime.has_value())
        {
            std::chrono::nanoseconds TickCount = std::chrono::duration_cast<std::chrono::nanoseconds>(CurrentTime - m_Implementation->m_PrevTime.value());
            m_Implementation->m_PrevTime = CurrentTime;
            return TickCount.count();
        }
        m_Implementation->m_PrevTime = CurrentTime;

        return 0;
    }

    /*static*/ long long Timer::GetTimestempForFps(const long long InFps)
    {
        return GetTicksPerSecond() / InFps;
    }

    /*static*/ long long Timer::GetTicksPerSecond()
    {
        using namespace std::chrono_literals;
        static const std::chrono::nanoseconds s_NanoSecondsInSecond(1s);

        return s_NanoSecondsInSecond.count();
    }
}