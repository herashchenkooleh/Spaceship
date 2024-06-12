#include "ssg/WeaponComponent.hpp"
#include "ssg/InputListenerComponent.hpp"
#include "ssg/GameObject.hpp"

namespace ssg
{
    WeaponComponent::WeaponComponent(GameObject* InOwmer, const String& InWeaponMesh, const float InWeaponSpeed, const int InWeaponLayer)
    {
        m_Weapon = MakeShared<Weapon>(InOwmer, InWeaponMesh, InWeaponLayer, InWeaponSpeed);
    }
    
    /*virtual*/ WeaponComponent::~WeaponComponent() = default;

    void WeaponComponent::OnMouseLeftButtonReleased(const InputEvent& InEvent)
    {
        if (m_Weapon)
        {
            m_Weapon->Shoot();
        }
    }
}