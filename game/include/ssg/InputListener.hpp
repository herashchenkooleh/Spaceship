#pragma once

#include "ssg/Global.hpp"
#include "ssg/Object.hpp"
#include "ssg/InputEvent.hpp"

namespace ssg
{
    class InputListener : public virtual Object
    {
    public:
        using Ptr = SharedPtr<InputListener>;
        
        InputListener(const Vector<InputEvent::Type>& InEventTypes);
        virtual ~InputListener();

        virtual void HandleInput(const InputEvent& InEvent);

        const Vector<InputEvent::Type>& GetEventTypes() const { return m_EventTypes; };

    private:
        Vector<InputEvent::Type> m_EventTypes;
    };
}