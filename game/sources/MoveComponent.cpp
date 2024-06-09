#include "ssg/MoveComponent.hpp"
#include "ssg/TransformComponent.hpp"

namespace ssg
{
    MoveComponent::MoveComponent()
        : m_Speed({ 0.0f, 0.0f })
    {

    }
    
    MoveComponent::~MoveComponent() = default;

    /*virtual*/ void MoveComponent::Update(const float InDeltaTime) /*override*/
    {
        if (TransformComponent::Ptr TComponent = GetComponent<TransformComponent>())
        {
            Transform& CurrentTransform = TComponent->GetTransform();
            CurrentTransform.SetRotation(m_Rotation);
            Vector2D NewPosition = CurrentTransform.GetPosition() + m_Speed * InDeltaTime;
            CurrentTransform.SetPosition(NewPosition);
        }
    }
}
