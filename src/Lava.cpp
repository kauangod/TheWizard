#include "../include/Entities/Obstacles/Lava.h"

Entities::Obstacles::Lava::Lava(const sf::Vector2f pos):
    Obstacle(pos, sf::Vector2f(128.f,128.f), true, ID::lava)
{
    animation.Reset("Assets/Lava.png", pos, sf::Vector2f(128.f,128.f));
}

Entities::Obstacles::Lava::~Lava()
{
}

void Entities::Obstacles::Lava::Move()
{
    this->Move();
	HitBox.setPosition(Position);
}

void Entities::Obstacles::Lava::Update()
{
    animation.Update(Position);
    animation.Draw();
    Gravity();
    Velocity.y -= forca_empuxo * dt * MULT;
    Position.y += Velocity.y;
}
#define JUMPHEIGHT -15
void Entities::Obstacles::Lava::OnCollision(Entities::Entity* ent)
{
    Entities::Characters::Character* pChar = static_cast<Entities::Characters::Character*>(ent);
	pChar->Damage(true);
	sf::Vector2f vel = sf::Vector2f( 0, JUMPHEIGHT/2);
	if(pChar->getPosition().x > Position.x)
		vel.x = -JUMPHEIGHT;
	else
		vel.x = JUMPHEIGHT;
	pChar->setVelocity(vel);
	pChar = NULL;
}
