#pragma once

#include "ssg/Global.hpp"
#include "ssg/GameObject.hpp"

namespace ssg
{
    class ISubSystem
    {
    public:
        using Ptr = SharedPtr<ISubSystem>;

        ISubSystem();
        virtual ~ISubSystem();

        virtual bool Initialize() = 0;
        virtual void Update(const float InDeltaTime) = 0;
        virtual void Deinitialize() = 0;
    };
}
