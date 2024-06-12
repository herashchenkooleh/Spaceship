#pragma once

#include "ssg/Pawn.hpp"
#include "ssg/Vector2D.hpp"
#include <random> //TODO!!!

namespace ssg
{
    class AsteroidSpawner : public GameObject
    {
        struct Implementation;
        using ImplementatioPtr = SharedPtr<Implementation>;

        template<typename Distributor, typename Type>
        struct Random
        {
            std::random_device m_OSSeed;
            std::mt19937 m_Generator;
            Distributor m_Distribute;

            Random(const Type InMin, const Type InMax)
                : m_Generator(m_OSSeed())
                , m_Distribute{ InMin, InMax }
            {

            }

            Random& operator=(const Random& InRandom)
            {
                if (this != &InRandom)
                {
                    m_Generator = InRandom.m_Generator;
                    m_Distribute = InRandom.m_Distribute;
                }

                return *this;
            }


            Type Get()
            {
                return m_Distribute(m_Generator);
            }
        };

    public:
        using Ptr = SharedPtr<AsteroidSpawner>;

        AsteroidSpawner(const String& InAsteroidsMesh, const float InAsteroidsSpeed, const float InSpawnInterval);
        virtual ~AsteroidSpawner();

        virtual void Update(const float InDeltaTime) override;

        void AddTarget(Pawn::Ptr InTarget);
        void RemoveTarget(Pawn::Ptr InTarget);

        static bool RegisterScriptType();

    private:
        Map<Object::Identifier, Pawn::Ptr> m_Targets;
        float m_AccumulatedTime;
        float m_SpawnInterval;

        String  m_AsteroidsMesh;
        float m_AsteroidsSpeed;

        Random<std::uniform_int_distribution<size_t>, size_t> m_SideSelect;
        Random<std::uniform_real_distribution<float>, float> m_PositionXSelect;
        Random<std::uniform_real_distribution<float>, float> m_PositionYSelect;

        Random<std::uniform_int_distribution<size_t>, size_t> m_TargetSelect;
    };
}