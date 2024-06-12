#include "ssg/MoveComponent.hpp"
#include "ssg/TransformComponent.hpp"

namespace ssg
{
    MoveComponent::MoveComponent()
        : m_Acceleration({ 0.0f, 0.0f })
        , m_Speed(0.0)
        , m_LookAt(0.0)
    {

    }
    
    MoveComponent::~MoveComponent() = default;

    /*virtual*/ void MoveComponent::Update(const float InDeltaTime) /*override*/
    {
        if (TransformComponent::Ptr TComponent = GetComponent<TransformComponent>())
        {
            Transform& CurrentTransform = TComponent->GetTransform();
            Vector2D NewPosition = CurrentTransform.GetPosition() + (m_Acceleration * m_Speed) * InDeltaTime;
            CurrentTransform.SetPosition(NewPosition);
        }
    }
}
