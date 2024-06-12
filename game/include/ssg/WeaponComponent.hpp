#pragma once

#include "ssg/Waepon.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class WeaponComponent : public GameObjectComponent
    {
    private:
        WeaponComponent();
        virtual ~WeaponComponent();

        virtual void Update(const float InDeltaTime);

        virtual bool Construct();
        virtual bool Destroy();
    };
}