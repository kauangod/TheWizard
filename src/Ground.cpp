#include "../include/Entities/Obstacles/Ground.h"
#define SIZEX 128.f
#define SIZEY 128.f
Entities::Obstacles::Ground::Ground(const sf::Vector2f pos):
	Obstacle(pos, sf::Vector2f(SIZEX, SIZEY), true, ID::ground)
{
	HitBox.setOrigin(SIZEX / 2, SIZEY / 2);
	
	HitBox.setTexture(texture);
}

Entities::Obstacles::Ground::~Ground()
{
}

void Entities::Obstacles::Ground::OnCollision(Entities::Entity* ent)
{
}

void Entities::Obstacles::Ground::Move()
{
    Gravity();
    Velocity.y -= forca_empuxo * dt * MULT;
    Position.y += Velocity.y;
}

void Entities::Obstacles::Ground::Update()
{
	this->Move();
	HitBox.setPosition(Position);
}

sf::Texture* Entities::Obstacles::Ground::texture(Managers::GraphicManager::getInstance()->loadTexture("Assets/Ground2.png"));
