#include "ssg/Timer.hpp"

#include <chrono>
#include <optional>

namespace ssg
{
    struct Timer::Implementation
    {
        std::optional<std::chrono::time_point<std::chrono::system_clock>> m_PrevTime;
    };

    Timer::Timer()
        : m_Implementation(MakeShared<Implementation>())
    {

    }

    Timer::~Timer() = default;

    unsigned long long Timer::Reset()
    {
        auto CurrentTime = std::chrono::system_clock::now();
        if (m_Implementation->m_PrevTime.has_value())
        {
            std::chrono::milliseconds TickCount = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - m_Implementation->m_PrevTime.value());
            m_Implementation->m_PrevTime = CurrentTime;
            return TickCount.count();
        }
        m_Implementation->m_PrevTime = CurrentTime;

        return 0;
    }

    /*static*/ unsigned long long Timer::GetTimestempForFps(const long long InFps)
    {
        return GetTicksPerSecond() / InFps;
    }

    /*static*/ unsigned long long Timer::GetTicksPerSecond()
    {
        using namespace std::chrono_literals;
        static const std::chrono::milliseconds s_NanoSecondsInSecond(1s);

        return s_NanoSecondsInSecond.count();
    }
}