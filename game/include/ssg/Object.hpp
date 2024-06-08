#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class Object
    {
    public:
        using Ptr = SharedPtr<Object>;
        using Identifier = unsigned int;

        Object();
        virtual ~Object();

        Identifier GetID() const { return m_ID; };

        friend bool operator==(const Object& InLhl, const Object& InRhl)
        {
            return InLhl.GetID() == InRhl.GetID();
        }

    private:
        Identifier m_ID;

        static Identifier s_Counter;
    };
}