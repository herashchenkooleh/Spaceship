#pragma once

#include "ssg/InputListener.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class InputListenerComponent : public GameObjectComponent, public InputListener
    {
    public:
        using Ptr = SharedPtr<InputListenerComponent>;

        using EventCallback = Function<void(const InputEvent&)>;

        InputListenerComponent();
        virtual ~InputListenerComponent();

        virtual void HandleInput(const InputEvent& InEvent) override;

        void AddCallback(const InputEvent::Type InEventType, EventCallback InCallback);

    private:
        Map<InputEvent::Type, EventCallback> m_Callbacks;
    };
}
