#pragma once

#include "Configs.hpp"

namespace SpaceShipGame
{
    class Vector2D
    {
    public:
        Vector2D();
        Vector2D(const int InXCoord, const int InYCoord);

        Vector2D(const Vector2D& InVector2D);
        Vector2D& operator=(const Vector2D& InVector2D);

        ~Vector2D();

        int GetX() const { return m_XCoord; };
        int GetY() const { return m_YCoord; };

        void SetX(const int InCoordX) { m_XCoord = InCoordX; };
        void SetY(const int InCoordY) { m_YCoord = InCoordY; };

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

        friend Vector2D operator+(const Vector2D& InLhl, const int InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord + InRhl;
            Temp.m_YCoord = InLhl.m_YCoord + InRhl;

            return Temp;
        }

        friend Vector2D operator-(const Vector2D& InLhl, const int InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord - InRhl;
            Temp.m_YCoord = InLhl.m_YCoord - InRhl;

            return Temp;
        }

        friend Vector2D operator*(const Vector2D& InLhl, const int InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord * InRhl;
            Temp.m_YCoord = InLhl.m_YCoord * InRhl;

            return Temp;
        }

        friend Vector2D operator/(const Vector2D& InLhl, const int InRhl)
        {
            Vector2D Temp;

            Temp.m_XCoord = InLhl.m_XCoord / InRhl;
            Temp.m_YCoord = InLhl.m_YCoord / InRhl;

            return Temp;
        }

        Vector2D& operator+=(const int InObj)
        {
            m_XCoord += InObj;
            m_YCoord += InObj;

            return *this;
        }

        Vector2D& operator-=(const int InObj)
        {
            m_XCoord -= InObj;
            m_YCoord -= InObj;

            return *this;
        }

        Vector2D& operator*=(const int InObj)
        {
            m_XCoord *= InObj;
            m_YCoord *= InObj;

            return *this;
        }

        Vector2D& operator/=(const int InObj)
        {
            m_XCoord /= InObj;
            m_YCoord /= InObj;

            return *this;
        }

    private:
        int m_XCoord;
        int m_YCoord;
    };
}