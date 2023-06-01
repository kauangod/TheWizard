#pragma once
#include "List.h"
#include "../Entities/Characters/Character.h"
#include "../Entities/Projectile.h"
#include <iostream>

namespace Math
{
	class EntityList
	{
	public:
		EntityList();
		~EntityList();
		void UpdateEntities();
		void DrawEntities();
		void Push_BackEntity(Entities::Entity* ent);
		void Push_FrontEntity(Entities::Entity* ent);
		void Clear();
		void DeleteEntities();
		void Save(std::ofstream& savefile);
		Math::List<Entities::Entity>& getTList();
		/* **Terminar esta Classe . . .*/
	private:
		EntityTList entity_list;
		EntityTList::Iterator listIt;
	};
}
