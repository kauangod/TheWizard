#pragma once

#include "../Character.h"

namespace Entities
{
    namespace Characters
    {
        namespace Enemies
        {
        class Enemy : public Characters::Character
        {
        private:
        public:
            Enemy(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isS = false, ID id = ID::empty, int lves = 0);
            virtual ~Enemy();
            virtual void Move() = 0;
            virtual void Attack(const bool b) = 0;
            virtual void Update() = 0;
            virtual void Draw() = 0;
            virtual void OnCollision(Entity* ent);
        protected:
        };
        }
    }
}