#pragma once

#include "ssg/Vector2D.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class MeshComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<MeshComponent>;

        MeshComponent(const String InTexture);
        ~MeshComponent();

        const String& GetTexture() const;

        void SetVisible(const bool InVisibility) { m_Visible = InVisibility; }
        bool IsVisible() const { return m_Visible; }

        const FloatRect& GetViewRect() const { return m_ViewRect; }
        void SetViewRect(const FloatRect& InRect) { m_ViewRect = InRect; }

    private:
        String m_Texture;
        bool m_Visible;
        FloatRect m_ViewRect;
    };
}