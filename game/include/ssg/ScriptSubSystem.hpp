#pragma once

#include "ssg/ISubSystem.hpp"
#include 

namespace ssg
{
    class ScriptSubSystem : public ISubSystem
    {
    public:
        using Ptr = SharedPtr<ScriptSubSystem>;

        ScriptSubSystem();
        virtual ~ScriptSubSystem();

        virtual bool Initialize() override;
        virtual void Update(const float InDeltaTime) override;
        virtual void Deinitialize() override;
    };
}