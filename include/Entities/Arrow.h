#pragma once

#include "Projectile.h"

namespace Entities{
    class Arrow : public Entities::Projectile {
    public:
        Arrow (sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f velocity = sf::Vector2f(0, 0), Entities::Characters::Character *owner = NULL);
        ~Arrow ();
        void Move();
    };
}