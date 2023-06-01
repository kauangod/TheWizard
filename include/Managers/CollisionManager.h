#pragma once
#include "../Entities/Entity.h"
#include "../Entities/Characters/Character.h"
#include "../Entities/Projectile.h"
#include "../Math/List.h"

namespace Managers
{

	class CollisionManager
	{
	public:
		CollisionManager();
		~CollisionManager();
		void setSList(Math::List<Entities::Entity>& ents);
		void setDList(Math::List<Entities::Entity>& ents);
		void Manage();
		void normalCollision(Entities::Entity* ent, float dist_x, float dist_y, float size_x, float size_y, ID id);
	private:
		Math::List<Entities::Entity>* Dentities;
		Math::List<Entities::Entity>* Sentities;
	};
}
