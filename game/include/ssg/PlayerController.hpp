#pragma once

#include "ssg/InputEvent.hpp"
#include "ssg/GameObject.hpp"

namespace ssg
{
    class PlayerController : public GameObject
    {
    public:
        using Ptr = SharedPtr<PlayerController>;

        PlayerController();
        ~PlayerController();

        virtual bool Construct() override;
        virtual bool Destroy() override;

        bool Initialize(GameObject::Ptr InObject);

        void OnKeyPressed(const InputEvent& InEvent);
        void OnKeyReleased(const InputEvent& InEvent);
        void OnMouseMove(const InputEvent& InEvent);

    protected:
        void UpdatePosition();
        
    private:
        GameObject::Ptr m_Object;
        
        Vector2D m_Speed;
        Vector2D m_MousePosition;
    };
}
