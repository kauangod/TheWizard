#include "../include/Entities/PlayerProjectile.h"
Entities::PlayerProjectile::PlayerProjectile(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner) 
: Projectile (pos, velocity, owner){ }

Entities::PlayerProjectile::~PlayerProjectile(){ } 

void Entities::PlayerProjectile::Move()
{
    Gravity();
    Velocity.y -= 1.f * gravity * dt * 60;
    Position.x += Velocity.x * dt * 60;
    Position.y += Velocity.y * dt * 60;
}

