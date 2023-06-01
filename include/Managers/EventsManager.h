#pragma once

#include "GraphicManager.h"
#include <SFML/Window.hpp>
#include "InputManager.h"

namespace Managers
{
	class EventsManager
	{
	public:
		EventsManager();
		~EventsManager();
		void Manage();
		void setpInputManager(Managers::InputManager* pIM);
	private:
		Managers::GraphicManager* pGM;
		Managers::InputManager* pIM;
	};
}