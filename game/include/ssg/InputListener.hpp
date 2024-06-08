#pragma once

#include "ssg/Global.hpp"
#include "ssg/Object.hpp"
#include "ssg/InputEvent.hpp"

namespace ssg
{
    class InputListener : public Object
    {
    public:
        using Ptr = SharedPtr<InputListener>;

        InputListener();
        virtual ~InputListener();

        virtual void HandleInput(const InputEvent& InEvent);
    };
}