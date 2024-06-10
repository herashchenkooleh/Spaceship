#pragma once

#include "ssg/Object.hpp"

namespace ssg
{
    class IScript : public Object
    {
    public:
        using Ptr = SharedPtr<IScript>;

        IScript();
        virtual ~IScript();

        virtual bool Execute(const String& InFilePath) = 0;
    };
}