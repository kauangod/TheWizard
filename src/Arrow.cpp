#include "../include/Entities/Arrow.h"
Entities::Arrow::Arrow(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner) 
: Projectile (pos, velocity, owner){ }

Entities::Arrow::~Arrow(){ } 

void Entities::Arrow::Move()
{
    Velocity.y -= 1.f * gravity * dt * 60;
    Position.y += Velocity.y * dt * 60;
    Gravity();
    Position.x += Velocity.x * dt * 60;
    Position.y += Velocity.y * dt * 60;
}