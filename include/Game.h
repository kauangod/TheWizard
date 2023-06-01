#pragma once
#include "Managers/EventsManager.h"
#define FPS 0
#include <iostream>
#include "Levels/Level1.h"
#include "States/StateMachine.h"
#include "Managers/InputManager.h"
#include "Menus/MainMenu.h"
#include "Menus/PauseMenu.h"
#include "States/LoadGameState.h"
#include "States/NewGameState.h"

class Game: public States::StateMachine
{
public:
	Game();
	~Game();
	void Run();

private:
	Managers::EventsManager* eManager;
	Managers::GraphicManager* pGM;
	Managers::InputManager* iManager;
};
