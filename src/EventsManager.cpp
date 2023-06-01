#include "../include/Managers/EventsManager.h"

using namespace Managers;

EventsManager::~EventsManager()
{
	pGM = NULL;
}

EventsManager::EventsManager():
	pGM(Managers::GraphicManager::getInstance())
{
}

void EventsManager::setpInputManager(Managers::InputManager* pIM)
{
	if(pIM)
		this->pIM = pIM;
}

void EventsManager::Manage()
{
	sf::Event event;
	while (pGM->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			pIM->pressedInput(event.key);
		}
		if (event.type == sf::Event::KeyReleased)
		{
			pIM->releasedInput(event.key);
		}
		if (event.type == sf::Event::Closed)
			pGM->Close();
	}
}

