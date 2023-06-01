#pragma once

#include <SFML/Graphics.hpp>
#include "../Being.h"
#include <iostream>
#include <fstream>
#include <math.h> //Fazer uma Fun��o ABS
#define MULT 60
namespace Entities
{
	class Entity : public Being
	{
	public:
		Entity(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isS = false, ID id = ID::empty);
		virtual ~Entity();
		virtual void Move() = 0;
		virtual void Update() = 0;
		virtual void Save(std::ofstream& savefile) = 0;
		virtual void Draw() = 0;
		void Gravity();
		const bool getGrounded() const;
		bool getisStatic();
		static unsigned int getContEntities();
		static float getDt();
		sf::Vector2f getPosition() const;
		sf::Vector2f getSize() const;
		sf::Vector2f getVelocity() const;
		void setGrounded(bool b);
		void setPosition(sf::Vector2f pos);
		void setPosition(float x, float y);
		void setVelocity(sf::Vector2f vel);
		void setVelocity(float x, float y);
		virtual void OnCollision(Entity* ent);
		static void updateDeltaTime(float dt);
	private:
		static unsigned int Cont;
	protected:
		static float dt;
		const bool isStatic;
		sf::Vector2f Velocity;
		sf::Vector2f Position;
		sf::Vector2f Size;
		static const float gravity;
		bool grounded;
		sf::RectangleShape HitBox;
	};
}
