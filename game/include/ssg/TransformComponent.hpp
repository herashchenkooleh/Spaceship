#pragma once

#include "ssg/Transform.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class TransformComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<TransformComponent>;

        TransformComponent();
        virtual ~TransformComponent();

        Transform& GetTransform() { return m_Transform; }
        void SetTransform(const Transform& InTransform) { m_Transform = InTransform; }

    private:
        Transform m_Transform;
    };
}
