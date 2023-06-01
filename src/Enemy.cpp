#include "../include/Entities/Characters/Enemies/Enemy.h"
#include "../Player.h"
#define dEnemy Entities::Characters::Enemies::Enemy
#define SIZEX 61.f
#define SIZEY 100.f
#define ESPEED 0.1


dEnemy::Enemy(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, ID id, int lves):
    Character(pos, size, isS, id, lves)
{
}


dEnemy::Enemy::~Enemy()
{
}

void dEnemy::Enemy::OnCollision(Entities::Entity* ent) 
{
	if(ent->getID() == ID::player)
	{
		Attack(true);
		Entities::Characters::Player* pPlayer = static_cast<Entities::Characters::Player*>(ent);
		pPlayer->Damage(true);
		sf::Vector2f vel = sf::Vector2f( 0, JUMPHEIGHT/2);
		if(pPlayer->getPosition().x > Position.x)
			vel.x = -JUMPHEIGHT;
		else
			vel.x = JUMPHEIGHT;
		pPlayer->setVelocity(vel);
		pPlayer = NULL;
	}
	else
	{
		Attack(false);
	}
}