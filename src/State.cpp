#include "../include/States/State.h"

#include "../include/States/StateMachine.h"

States::State::State(StateMachine* pSMachine, States::stateID id):
    pSMachine(pSMachine),
    id(id)
{
}

States::State::~State()
{
    pSMachine = NULL;
}

void States::State::setStateMachine(StateMachine* pSMachine)
{
    this->pSMachine = pSMachine;
}

void States::State::changeState(States::stateID sID)
{
    isRunning = false;
    previousState = this;
    pSMachine->changeCurrentState(sID);
}

const bool States::State::getIsRunning() const {return isRunning;}

const States::stateID States::State::getStateID() const {return id;}

void States::State::Reset()
{
}


States::State* States::State::previousState(NULL);