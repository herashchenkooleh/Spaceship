#include "ssg/Vector2D.hpp"

namespace ssg
{
    Vector2D::Vector2D()
        : m_XCoord(0)
        , m_YCoord(0)
    {

    }

    Vector2D::Vector2D(const float InXCoord, const float InYCoord)
        : m_XCoord(InXCoord)
        , m_YCoord(InYCoord)
    {

    }

    Vector2D::Vector2D(const Vector2D& InVector2D)
        : m_XCoord(InVector2D.m_XCoord)
        , m_YCoord(InVector2D.m_YCoord)
    {

    }

    Vector2D& Vector2D::operator=(const Vector2D& InVector2D)
    {
        if (this != &InVector2D)
        {
            m_XCoord = InVector2D.m_XCoord;
            m_YCoord = InVector2D.m_YCoord;
        }

        return *this;
    }

    Vector2D::~Vector2D() = default;
}