#include "../include/States/StateMachine.h"

States::StateMachine::StateMachine()
{
}

States::StateMachine::~StateMachine()
{ 
}

void States::StateMachine::changeCurrentState(States::stateID sId)
{
    currentState = sId;
}


void States::StateMachine::runCurrentState()
{
    statesMap[currentState]->Update();
    statesMap[currentState]->Draw();
}

const States::stateID States::StateMachine::getCurrentStateID() {return currentState;}

void States::StateMachine::push_State(States::State* pS) 
{
    statesMap[pS->getStateID()] = pS;
}