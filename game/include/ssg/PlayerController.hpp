#pragma once

#include "ssg/GameObject.hpp"
#include "ssg/InputListener.hpp"

namespace ssg
{
    class PlayerController : public InputListener
    {
    public:
        using Ptr = SharedPtr<PlayerController>;

        PlayerController();
        ~PlayerController();

        bool Initialize(GameObject::Ptr InObject);

        virtual void HandleInput(const InputEvent& InEvent) override;

    protected:
        void UpdatePosition();
        
    private:
        GameObject::Ptr m_Object;
        
        Vector2D m_Speed;
        Vector2D m_MousePosition;
    };
}
