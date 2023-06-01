#include "../include/States/NewGameState.h"



States::NewGameState::NewGameState(States::StateMachine* pSMachine):
    State(pSMachine, States::stateID::newGameState)
{
}

States::NewGameState::~NewGameState()
{
}

void States::NewGameState::Update()
{
    std::cout<< "NewGame" << std::endl;
    std::list<Levels::Level*>::iterator it;
    for(it = levels.begin(); it != levels.end(); it++)
    {
        if((*it)->getStateID() == stateID::level1)
        {
            if(!(*it)->getLevelStarted())
            {
                std::cout<< "Change State" << std::endl;
                changeState(stateID::level1);
                return;
            }
            else
                break;
        }
    }
    std::cout<< "Reset Starting" << std::endl;
    for(it = levels.begin(); it != levels.end(); it++)
    {
        (*it)->Reset();
    }
    changeState(stateID::level1);
    /*  */
}

void States::NewGameState::Draw()
{
}

void States::NewGameState::PushLevel(Levels::Level* level)
{
    levels.push_back(level);
}