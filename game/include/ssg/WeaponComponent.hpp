#pragma once

#include "ssg/InputEvent.hpp"
#include "ssg/Weapon.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class WeaponComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<WeaponComponent>;

        WeaponComponent(class GameObject* InOwmer, const String& InWeaponMesh, const float InWeaponSpeed, const int InWeaponLayer);
        virtual ~WeaponComponent();

        Weapon::Ptr GetWeapon() { return m_Weapon; }
        void SetWeapon(Weapon::Ptr InWeapon) { m_Weapon = InWeapon; }

        void OnMouseLeftButtonReleased(const InputEvent& InEvent);

    private:
        Weapon::Ptr m_Weapon;
    };
}