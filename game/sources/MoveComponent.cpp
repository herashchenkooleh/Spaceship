#include "ssg/MoveComponent.hpp"
#include "ssg/PositionComponent.hpp"
#include "ssg/RotationComponent.hpp"

namespace ssg
{
    MoveComponent::MoveComponent()
        : m_Speed({ 0.0f, 0.0f })
    {

    }
    
    MoveComponent::~MoveComponent() = default;

    /*virtual*/ void MoveComponent::Update(const float InDeltaTime) /*override*/
    {
        if (PositionComponent::Ptr PosComponent = GetComponent<PositionComponent>())
        {
            Vector2D NewPosition = PosComponent->GetPosition() + m_Speed * InDeltaTime;
            PosComponent->SetPosition(NewPosition);
        }
        
        if (RotationComponent::Ptr RComponent = GetComponent<RotationComponent>())
        {
            RComponent->SetDegrees(m_Rotation);
        }
    }
}
