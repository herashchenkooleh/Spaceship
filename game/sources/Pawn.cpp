#include "ssg/Pawn.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/MeshComponent.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"

namespace ssg
{
    /*static*/ bool Pawn::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<Pawn>("Pawn", sol::constructors<Pawn(const String&, const Transform&)>(), sol::base_classes, sol::bases<GameObject>());
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

    Pawn::Pawn(const String& InTexturePath, const Transform& InTransform)
        : m_TexturePath(InTexturePath)
        , m_SpawnTransform(InTransform)
    {

    }

    /*virtual*/ Pawn::~Pawn() = default;

    /*virtual*/ bool Pawn::Construct() /*override*/
    {
        TransformComponent::Ptr TComponent = AddComponent<TransformComponent>();
        if(auto MComponent = AddComponent<MeshComponent>(m_TexturePath))
        {
            TComponent->SetTransform(m_SpawnTransform);
            MComponent->AddComponent<TransformComponent>(TComponent);
        }

        if (MoveComponent::Ptr MoveObjectComponent = AddComponent<MoveComponent>())
        {
            MoveObjectComponent->AddComponent<TransformComponent>(TComponent);
        }

        return true;
    }
}