#pragma once
#include "State.h"
#include <map>
//#include "../Math/List.h"

namespace States
{
    class StateMachine
    {
    public:
        StateMachine();
        virtual ~StateMachine();
        void changeCurrentState(States::stateID sId);
        void runCurrentState();
        const States::stateID getCurrentStateID();
        void push_State(States::State* pS);
    protected:
        States::stateID currentState;

        std::map<stateID ,States::State*> statesMap;
        //States::State* currentState;
    };
}