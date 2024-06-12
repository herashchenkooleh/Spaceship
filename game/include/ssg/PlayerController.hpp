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

        virtual void Update(const float InDeltaTime) override;

        bool Initialize(const String& InFilePath, GameObject::Ptr InObject);
        void Deinitialize();

        void OnKeyPressed(const InputEvent& InEvent);
        void OnKeyReleased(const InputEvent& InEvent);
        void OnMouseMove(const InputEvent& InEvent);
        void OnMouseButtonReleased(const InputEvent& InEvent);

        static bool RegisterScriptType();

        void SetSpeed(const float InSpeed) { m_Speed = InSpeed; }
        float GetSpeed() const { return m_Speed; }
        
    private:
        GameObject::Ptr m_Object;
        
        float m_Speed;

        Vector2D m_Acceleration;
        Vector2D m_MousePosition;
    };
}
