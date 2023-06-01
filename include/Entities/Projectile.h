#pragma once

#include "Characters/Character.h"
#include "Entity.h"
namespace Entities
{
    class Projectile : public Entity
    {
    public:
        Projectile(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f Velocity = sf::Vector2f(0, 0), Entities::Characters::Character *owner = NULL);
        ~Projectile();
        void Update();
        void Draw();
        void Shoot(sf::Vector2f pos, sf::Vector2f vel);
        void OnCollision(Entities::Entity *ent);
        const bool getCollided() const;
        void Save(std::ofstream& savefile);
        void Load(std::ifstream& savefile);
        virtual void Move() = 0;
    protected:
        Entities::Characters::Character *owner;
        bool collided;
    };
}