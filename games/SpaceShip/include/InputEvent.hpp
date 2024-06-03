#pragma once

namespace SpaceShipGame
{
    class InputEvent
    {
    public:
        enum class Type
        {
            Exit,
            Unkwnown
        };

        InputEvent();
        ~InputEvent();

        void SetType(const Type& InType) { m_Type = InType; }
        Type GetType() const { return m_Type; }

    private:
        Type m_Type;
    };
}