#include "../include/Entities/Characters/Enemies/Archer.h"

#define SIZEX 30.f
#define SIZEY 60.f
#define ESPEED 0.1

#define dEnemy Entities::Characters::Enemies

dEnemy::Archer::Archer(const sf::Vector2f pos):
    Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::archer, 7)
{
    HitBox.setOrigin(SIZEX / 2, SIZEY / 2);
	HitBox.setTexture(texture);
	animation.pushAnimation(GraphicElements::Animation_ID::idle, "Assets/Archer-Idle.png", sf::Vector2u(7,0), 0.2f);
    for(int i = 0; i < 5; i++)
	{
		Arrow* pAux = new Arrow(sf::Vector2f(0,0), sf::Vector2f(0,0), this);
		if(!pAux)
		{
			std::cout << std::endl << "ERROR: Failed to Memory Allocate" << std::endl;
			exit(1);
		}
		aShots.push_back(pAux);
	}
}

dEnemy::Archer::~Archer()
{
    aShots.clear();
}

void dEnemy::Archer::Update()
{
	std::cout << lives << std::endl;
	std::cout << alive << std::endl;
    this->Gravity();
	this->Damage();
	HitBox.setPosition(Position);
	animation.Update( GraphicElements::Animation_ID::idle,\
	Position, false);
}

void dEnemy::Archer::Attack(const bool b)
{
    if (b)
		HitBox.setFillColor(sf::Color(sf::Color::Red));
	else
		HitBox.setFillColor(sf::Color(sf::Color::White));
}
std::vector<Entities::Arrow*>* Entities::Characters::Enemies::Archer::getShots()
{
    return &aShots;
}

void dEnemy::Archer::Move()
{
	this->Gravity();
}

void dEnemy::Archer::Draw()
{
	animation.Draw();
}

sf::Texture* dEnemy::Archer::texture(Managers::GraphicManager::getInstance()->loadTexture("Assets/Archer-Idle.png"));