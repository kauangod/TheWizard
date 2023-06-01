#include "../include/Observers/PlayerInputManager.h"

using namespace Observers;

PlayerInputManager::PlayerInputManager(Entities::Characters::Player *pP, Entities::Characters::Player *pP2, States::State* currentState) : 
	pPlayer(pP),																								  
	pPlayer2(pP2),
	jumpKeyReleased(true),
	jumpKeyReleased2(true),
	attackKeyReleased(true),
	attackKeyReleased2(true),
	currentState(currentState)
{
	inputSetsPlayer["Jump"] = "W";
	inputSetsPlayer["Right"] = "D";
	inputSetsPlayer["Left"] = "A";
	inputSetsPlayer["Down"] = "S";
	inputSetsPlayer["Attack"] = "F";
	inputSetsPlayer2["Jump"] = "Up";
	inputSetsPlayer2["Right"] = "Right";
	inputSetsPlayer2["Left"] = "Left";
	inputSetsPlayer2["Down"] = "Down";
	inputSetsPlayer2["Attack"] = "rCtrl";
	mapIt = inputSetsPlayer.begin();
	mapIt2 = inputSetsPlayer2.begin();
}

PlayerInputManager::~PlayerInputManager()
{
	pPlayer = NULL;
	pPlayer2 = NULL;
}

void PlayerInputManager::notifyKeyPressed(std::string key)
{
	if(!currentState->getIsRunning())
		return;
	if(key == "Esc")
	{
		currentState->changeState(States::stateID::pauseMenu);

	}
	mapIt = inputSetsPlayer.begin();
	for (mapIt; mapIt != inputSetsPlayer.end(); mapIt++)
	{
		if (mapIt->second == key)
		{
			if (mapIt->first == "Jump")
			{
				if (jumpKeyReleased)
				{
					pPlayer->Jump();
					jumpKeyReleased = false;
				}
				break;
			}
			if (mapIt->first == "Right")
			{
				pPlayer->MoveRight(true);
				break;
			}
			if (mapIt->first == "Left")
			{
				pPlayer->MoveLeft(true);
				break;
			}
			if (mapIt->first == "Down")
			{
				pPlayer->Fall();
				break;
			}
			if (mapIt->first == "Attack")
			{
				if(attackKeyReleased)
				{ 
					pPlayer->Attack(true);
					attackKeyReleased = false;
				}
				break;
			}
		}
	}
	if (pPlayer2)
	{
		mapIt2 = inputSetsPlayer2.begin();
		for (mapIt2; mapIt2 != inputSetsPlayer2.end(); mapIt2++)
		{
			if (mapIt2->second == key)
			{
				if (mapIt2->first == "Jump")
				{
					if (jumpKeyReleased2)
					{
						pPlayer2->Jump();
						jumpKeyReleased2 = false;
					}
					break;
				}
				if (mapIt2->first == "Right")
				{
					pPlayer2->MoveRight(true);
					break;
				}
				if (mapIt2->first == "Left")
				{
					pPlayer2->MoveLeft(true);
					break;
				}
				if (mapIt2->first == "Down")
				{
					pPlayer2->Fall();
					break;
				}
				if (mapIt2->first == "Attack")
				{
					if(attackKeyReleased2)
					{
						pPlayer2->Attack(true);
						attackKeyReleased2 = false;
					}
					break;
				}
			}
		}
	}
}

void PlayerInputManager::notifyKeyReleased(std::string key)
{
	if(!currentState->getIsRunning())
		return;
	mapIt = inputSetsPlayer.begin();
	for (mapIt; mapIt != inputSetsPlayer.end(); mapIt++)
	{
		if (mapIt->second == key)
		{
			if (mapIt->first == "Jump")
			{
				jumpKeyReleased = true;
				break;
			}
			if (mapIt->first == "Right")
			{
				pPlayer->MoveRight(false);
				break;
			}
			if (mapIt->first == "Left")
			{
				pPlayer->MoveLeft(false);
				break;
			}
			if (mapIt->first == "Attack")
			{
				attackKeyReleased = true;
				pPlayer->Attack(false);
				break;
			}
		}
	}
	if (pPlayer2)
	{
		mapIt2 = inputSetsPlayer2.begin();
		for (mapIt2; mapIt2 != inputSetsPlayer2.end(); mapIt2++)
		{
			if (mapIt2->second == key)
			{
				if (mapIt2->first == "Jump")
				{
					jumpKeyReleased2 = true;
					break;
				}
				if (mapIt2->first == "Right")
				{
					pPlayer2->MoveRight(false);
					break;
				}
				if (mapIt2->first == "Left")
				{
					pPlayer2->MoveLeft(false);
					break;
				}
				if (mapIt2->first == "Attack")
				{
					attackKeyReleased2 = true;
					pPlayer2->Attack(false);
					break;
				}
			}
		}
	}
}

void PlayerInputManager::setpPlayer(Entities::Characters::Player *pP)
{
	pPlayer = pP;
}

void PlayerInputManager::setpPlayer2(Entities::Characters::Player *pP)
{
	pPlayer2 = pP;
}
