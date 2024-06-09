#pragma once

#include "ssg/Object.hpp"

namespace ssg
{
    class IScriptBuilder : public Object
    {
    public:
        using Ptr = SharedPtr<IScriptBuilder>;

        IScriptBuilder();
        virtual ~IScriptBuilder();

        virtual bool ExecuteScript() = 0;
    };
}