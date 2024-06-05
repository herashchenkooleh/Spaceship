#pragma once

#include "Configs.hpp"

namespace SpaceShipGame
{
    class Vector2D
    {
    public:
        Vector2D();
        Vector2D(const float InXCoord, const float InYCoord);

        Vector2D(const Vector2D& InVector2D);
        Vector2D& operator=(const Vector2D& InVector2D);

        ~Vector2D();

        float GetX() const { return m_XCoord; };
        float GetY() const { return m_YCoord; };

        void SetX(const float InCoordX) { m_XCoord = InCoordX; };
        void SetY(const float InCoordY) { m_YCoord = InCoordY; };

        friend Vector2D operator+(const Vector2D& InLhl, const Vector2D& InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord + InRhl.m_XCoord;
            Temp.m_YCoord = InLhl.m_YCoord + InRhl.m_YCoord;

            return Temp;
        }

        friend Vector2D operator-(const Vector2D& InLhl, const Vector2D& InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord - InRhl.m_XCoord;
            Temp.m_YCoord = InLhl.m_YCoord - InRhl.m_YCoord;

            return Temp;
        }

        friend Vector2D operator*(const Vector2D& InLhl, const Vector2D& InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord * InRhl.m_XCoord;
            Temp.m_YCoord = InLhl.m_YCoord * InRhl.m_YCoord;

            return Temp;
        }

        friend Vector2D operator/(const Vector2D& InLhl, const Vector2D& InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord / InRhl.m_XCoord;
            Temp.m_YCoord = InLhl.m_YCoord / InRhl.m_YCoord;

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

    private:
        float m_XCoord;
        float m_YCoord;
    };
}