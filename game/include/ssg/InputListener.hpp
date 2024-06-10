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

        InputListener();
        virtual ~InputListener();

        virtual void HandleInput(const InputEvent& InEvent);

        void SetListenEventTypes(const Vector<InputEvent::Type>& InListenEventTypes) { m_ListenEventTypes = InListenEventTypes; }
        const Vector<InputEvent::Type>& GetEventTypes() const { return m_ListenEventTypes; };

    private:
        Vector<InputEvent::Type> m_ListenEventTypes;
    };
}