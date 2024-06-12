#pragma once

#include "ssg/Global.hpp"
#include "ssg/QuadTree.hpp"
#include "ssg/ISubSystem.hpp"
#include "ssg/CollisionComponent.hpp"

namespace ssg
{
    class CollisionSubSystem : public ISubSystem
    {
    public:
        using Ptr = SharedPtr<CollisionSubSystem>;

        CollisionSubSystem();
        virtual ~CollisionSubSystem();

        CollisionSubSystem(const CollisionSubSystem& InObj) = delete;
        CollisionSubSystem& operator=(const CollisionSubSystem& InObj) = delete;

        virtual bool Initialize() override;
        virtual void Update(const float InDeltaTime) override;
        virtual void Deinitialize() override;

        virtual void RegisterGameObject(GameObject::Ptr InObject) override;
        virtual void UnregisterGameObject(GameObject::Ptr InObject) override;

    private:
        Vector<CollisionComponent> m_Components;
    };
}