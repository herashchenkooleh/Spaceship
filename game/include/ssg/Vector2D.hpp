#pragma once

#include "ssg/Global.hpp"
#include <cmath>

namespace ssg
{
    class Vector2D
    {
    public:
        Vector2D();
        Vector2D(const float InCoord);
        Vector2D(const float InXCoord, const float InYCoord);

        Vector2D(const Vector2D& InVector2D);
        Vector2D& operator=(const Vector2D& InVector2D);

        ~Vector2D();

        float GetX() const { return m_XCoord; };
        float GetY() const { return m_YCoord; };

        void SetX(const float InCoordX) { m_XCoord = InCoordX; };
        void SetY(const float InCoordY) { m_YCoord = InCoordY; };
        
        float GetLength() const
        {
            return std::sqrtf(m_XCoord * m_XCoord + m_YCoord * m_YCoord);
        }
        
        Vector2D& Normalize()
        {
            const float Length = GetLength();
            m_XCoord /= Length;
            m_YCoord /= Length;
            
            return *this;
        }
        
        float GetAngle(const Vector2D& InVector) const
        {
            float Dot = (GetX() * GetY() + InVector.GetX() * InVector.GetY()) / (std::sqrtf(GetX() * GetX() + InVector.GetX() * InVector.GetX()) * std::sqrtf(GetY() * GetY() + InVector.GetY() * InVector.GetY()));
            return std::acosf(Dot);
        }

        Vector2D operator+(const Vector2D& InRhl) const
        {
            Vector2D Temp;

            Temp.m_XCoord = m_XCoord + InRhl.m_XCoord;
            Temp.m_YCoord = m_YCoord + InRhl.m_YCoord;

            return Temp;
        }

        Vector2D operator-(const Vector2D& InRhl) const
        {
            Vector2D Temp;

            Temp.m_XCoord = m_XCoord - InRhl.m_XCoord;
            Temp.m_YCoord = m_YCoord - InRhl.m_YCoord;

            return Temp;
        }

        Vector2D operator*(const Vector2D& InRhl) const
        {
            Vector2D Temp;

            Temp.m_XCoord = m_XCoord * InRhl.m_XCoord;
            Temp.m_YCoord = m_YCoord * InRhl.m_YCoord;

            return Temp;
        }

        Vector2D operator/(const Vector2D& InRhl) const
        {
            Vector2D Temp;

            Temp.m_XCoord = m_XCoord / InRhl.m_XCoord;
            Temp.m_YCoord = m_YCoord / InRhl.m_YCoord;

            return Temp;
        }

        Vector2D& operator+=(const Vector2D& InObj)
        {
            m_XCoord += InObj.m_XCoord;
            m_YCoord += InObj.m_YCoord;

            return *this;
        }

        Vector2D& operator-=(const Vector2D& InObj)
        {
            m_XCoord -= InObj.m_XCoord;
            m_YCoord -= InObj.m_YCoord;

            return *this;
        }

        Vector2D& operator*=(const Vector2D& InObj)
        {
            m_XCoord *= InObj.m_XCoord;
            m_YCoord *= InObj.m_YCoord;

            return *this;
        }

        Vector2D& operator/=(const Vector2D& InObj)
        {
            m_XCoord /= InObj.m_XCoord;
            m_YCoord /= InObj.m_YCoord;

            return *this;
        }

        friend Vector2D operator+(const Vector2D& InLhl, const float InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord + InRhl;
            Temp.m_YCoord = InLhl.m_YCoord + InRhl;

            return Temp;
        }

        friend Vector2D operator-(const Vector2D& InLhl, const float InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord - InRhl;
            Temp.m_YCoord = InLhl.m_YCoord - InRhl;

            return Temp;
        }

        friend Vector2D operator*(const Vector2D& InLhl, const float InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord * InRhl;
            Temp.m_YCoord = InLhl.m_YCoord * InRhl;

            return Temp;
        }

        friend Vector2D operator/(const Vector2D& InLhl, const float InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord / InRhl;
            Temp.m_YCoord = InLhl.m_YCoord / InRhl;

            return Temp;
        }

        Vector2D& operator+=(const float InObj)
        {
            m_XCoord += InObj;
            m_YCoord += InObj;

            return *this;
        }

        Vector2D& operator-=(const float InObj)
        {
            m_XCoord -= InObj;
            m_YCoord -= InObj;

            return *this;
        }

        Vector2D& operator*=(const float InObj)
        {
            m_XCoord *= InObj;
            m_YCoord *= InObj;

            return *this;
        }

        Vector2D& operator/=(const float InObj)
        {
            m_XCoord /= InObj;
            m_YCoord /= InObj;

            return *this;
        }

        static bool RegisterScriptType();

    private:
        float m_XCoord;
        float m_YCoord;
    };
}
