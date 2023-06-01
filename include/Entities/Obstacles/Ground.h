#pragma once
#include "Obstacle.h"
#include <iostream>
namespace Entities
{
	namespace Obstacles
	{
		class Ground : public Obstacles::Obstacle
		{
		private:
			static sf::Texture* texture;
		public:
			Ground(const sf::Vector2f pos);
			~Ground();
			void OnCollision(Entities::Entity* ent);
			void Move();
			void Update();
		};
	}
}