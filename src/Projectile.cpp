#include "../include/Entities/Projectile.h"


Entities::Projectile::Projectile(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character* owner):
	Entity(pos, sf::Vector2f(20,20), false, ID::projectile),
    owner(owner),
    collided(false)
{
    HitBox.setOrigin(sf::Vector2f(10,10));
	HitBox.setFillColor(sf::Color::Blue);
}

Entities::Projectile::~Projectile()
{
}

void Entities::Projectile::Update()
{
    Move();
    HitBox.setPosition(Position);
}

void Entities::Projectile::Draw()
{
	pGM->Draw(HitBox);
}


void Entities::Projectile::OnCollision(Entities::Entity* ent)
{
    if(ent->getID() != owner->getID() && ent->getID() != ID::obstacle && ent->getID() != ID::lava && ent->getID() != ID::ice && ent->getID() != ID::ground)
    {
        static_cast<Entities::Characters::Character*>(ent)->Damage(true);
    }
    collided = true;
}

void Entities::Projectile::Shoot(sf::Vector2f pos, sf::Vector2f vel)
{
    Position = pos;
    Velocity = vel;
    collided = false;
}

void Entities::Projectile::Save(std::ofstream& savefile)
{
    savefile << this->getID() << std::endl;
    savefile << collided << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
    savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl; 
}

void Entities::Projectile::Load(std::ifstream& savefile)
{
    float x;
    float y;
    int iread;
    savefile >> iread;
    savefile >> iread;
    collided = static_cast<bool>(iread);
	savefile >> x;
	savefile >> y;
    this->setPosition(x,y);
    savefile >> x;
	savefile >> y;
    this->setVelocity(x,y);
}

const bool Entities::Projectile::getCollided() const { return collided;}
