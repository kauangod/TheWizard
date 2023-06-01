#include "../include/Entities/Characters/Character.h"

Entities::Characters::Character::Character(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, ID id, int lves):
    Entity(pos, size, false, id),
    alive(true),
    damaged(false),
    lives(lves)
{
}

Entities::Characters::Character::~Character()
{
}

void Entities::Characters::Character::OnCollision(Entities::Entity* ent)
{
}

void Entities::Characters::Character::Damage(bool b)
{
    if(damaged)
        return;
    damaged = b;
    this->operator--();
    timecont = 0;
    Damage();
}

void Entities::Characters::Character::Damage()
{
    if(!damaged)
        return;
    timecont += dt;
    HitBox.setFillColor(sf::Color::Red);
    if(timecont >= 0.3)
    {
        HitBox.setFillColor(sf::Color::White);
        damaged = false;
    }
}

void Entities::Characters::Character::setAlive(bool alive) {this->alive = alive;}


void Entities::Characters::Character::setLives(int lives) { this->lives = lives;}


void Entities::Characters::Character::Save(std::ofstream& savefile)
{
    savefile << this->getID() << std::endl;
    savefile << lives << std::endl;
    savefile << alive << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
    savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
}

void Entities::Characters::Character::operator--() { lives--; if(lives <= 0) alive = false; }

const bool Entities::Characters::Character::getAlive() const { return alive; }