#include "MoveComponent.hpp"
#include "PositionComponent.hpp"

namespace SpaceShipGame
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
    }
}