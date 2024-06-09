#pragma once

#include "ssg/ISubSystem.hpp"
#include "ssg/GameWindow.hpp"
#include "ssg/GameObject.hpp"

namespace ssg
{
    class GameEngine
    {
    public:
        static GameEngine& GetInstance();

        GameEngine(const GameEngine& InObj) = delete;
        GameEngine& operator=(const GameEngine& InObj) = delete;

        bool Initialize(GameWindow::Ptr InWindow);
        void Deinitialize();

        void UpdateSubSystems(const float InDeltaTime);

        template<typename Type, typename ...Args>
        void RegisterSubSystem(Args... InArgs)
        {
            if (auto Iter = m_SubSystems.find(TypeIndex(typeid(Type))); Iter == m_SubSystems.end())
            {
                m_SubSystems[TypeIndex(typeid(Type))] = MakeShared<Type>(std::forward<Args>(InArgs)...);
            }
        }

        template<typename Type>
        void UnregisterSubSystem()
        {
            m_SubSystems.erase(TypeIndex(typeid(Type)));
        }

        template<typename Type>
        typename Type::Ptr GetSubSystem() const
        {
            if (auto Iter = m_SubSystems.find(TypeIndex(typeid(Type))); Iter != m_SubSystems.end())
            {
                return DynamicPointerCast<Type>(Iter->second);
            }

            return DynamicPointerCast<Type>(ISubSystem::Ptr{});
        }

        void RegisterGameObject(GameObject::Ptr InObject);
        void UnregisterGameObject(GameObject::Ptr InObject);

    private:
        GameEngine();
        ~GameEngine();
        
        GameWindow::Ptr m_Window;

        UnorderedMap<TypeIndex, ISubSystem::Ptr> m_SubSystems;
    };
}
