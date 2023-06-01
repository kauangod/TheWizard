#pragma once
#include "../Entity.h"


namespace Entities
{
    namespace Obstacles
    {
        class Obstacle : public Entities::Entity
        {
        protected:
            const static float forca_empuxo;
        public:
            Obstacle(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isS = true, ID id = ID::obstacle);
            virtual ~Obstacle();
            virtual void OnCollision(Entities::Entity* ent);
            virtual void Move() = 0;
            virtual void Update() = 0;
            void Draw();
            void Save(std::ofstream& savefile);
        };
    }
}