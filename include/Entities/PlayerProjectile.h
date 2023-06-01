#pragma once

#include "Projectile.h"

namespace Entities{
    class PlayerProjectile : public Projectile {
    public:
        PlayerProjectile (sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f velocity = sf::Vector2f(0, 0), Entities::Characters::Character *owner = NULL);
        ~PlayerProjectile ();
        void Move();
    };
}