#pragma once
#include "Observer.h"
#include "../Entities/Characters/Player.h"
#include "../States/StateMachine.h"

namespace Observers
{
    class PlayerInputManager : public Observers::Observer
    {
    public:
		PlayerInputManager(Entities::Characters::Player* pP = NULL, Entities::Characters::Player* pP2 = NULL, States::State* currentState = NULL);
		~PlayerInputManager();
		void notifyKeyPressed(std::string key);
		void notifyKeyReleased(std::string key);
		void setpPlayer(Entities::Characters::Player* pP);
		void setpPlayer2(Entities::Characters::Player* pP);
	private:
		bool jumpKeyReleased;
		bool jumpKeyReleased2;
		bool attackKeyReleased;	
		bool attackKeyReleased2;
		States::State* currentState;
		Entities::Characters::Player* pPlayer;
		Entities::Characters::Player* pPlayer2;
		std::map<std::string, std::string> inputSetsPlayer;
		std::map<std::string, std::string> inputSetsPlayer2;
		std::map<std::string, std::string>::const_iterator mapIt;
		std::map<std::string, std::string>::const_iterator mapIt2;
    };
}