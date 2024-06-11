#include "ssg/Vector2D.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"  

namespace ssg
{
    /*static*/ bool Vector2D::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<Vector2D>("Vector2D", sol::constructors<Vector2D(), Vector2D(const float), Vector2D(const float, const float)>(),
                                                       "X", &Vector2D::m_XCoord,
                                                       "Y", &Vector2D::m_YCoord,
                                                       sol::meta_function::addition, &Vector2D::operator+,
                                                       sol::meta_function::subtraction, &Vector2D::operator-,
                                                       sol::meta_function::multiplication, &Vector2D::operator*,
                                                       sol::meta_function::division, &Vector2D::operator/);
                    }
                }
            }
        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    Vector2D::Vector2D()
        : m_XCoord(0)
        , m_YCoord(0)
    {

    }

    Vector2D::Vector2D(const float InCoord)
        : m_XCoord(InCoord)
        , m_YCoord(InCoord)
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