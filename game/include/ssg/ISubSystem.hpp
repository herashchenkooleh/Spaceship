#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class ISubsystem
    {
    public:
        using Ptr = SharedPtr<ISubsystem>;

        ISubsystem();
        virtual ~ISubsystem();

        virtual bool Initialize() = 0;
        virtual void Update(const float InDeltaTime) = 0;
        virtual void Deinitialize() = 0;
    };
}
