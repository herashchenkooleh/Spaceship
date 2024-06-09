#pragma once

#include "ssg/Object.hpp"
#include "ssg/IScriptBuilder.hpp"

namespace ssg
{
    class Level : public EnableSharedFromThis<Level>
    {
        friend class LevelScriptBuilder;

    public:
        using Ptr = SharedPtr<Level>;

        Level();
        ~Level();

        bool Load(const String& InLvlScript);

    };
}