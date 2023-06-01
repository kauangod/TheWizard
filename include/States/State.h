#pragma once
#include <stdlib.h>

namespace States
{
    class StateMachine;

    enum stateID
    {
        empty =        -1,
        mainMenu =      0,
        level1 =        1,
        gameOver =      2,
        pauseMenu =     3,
        loadGameState = 4,
        newGameState  = 5
    };

    class State
    {
    public:
        State(StateMachine* pSMachine = NULL, States::stateID id = empty);
        virtual ~State();
        void setStateMachine(StateMachine* pSMachine);
        void changeState(States::stateID sID);
        const States::stateID getStateID() const;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void Reset();
        const bool getIsRunning() const;
    protected:
        bool isRunning;
        StateMachine* pSMachine;
        stateID id;
        static State* previousState;
    };
}