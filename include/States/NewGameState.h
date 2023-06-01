#pragma once

#include "State.h"
#include "../Levels/Level.h"


namespace States
{
    class NewGameState: public State
    {
    public:
        NewGameState(States::StateMachine* pSMachine);
        ~NewGameState();
        void Update();
        void Draw();
        void PushLevel(Levels::Level* level);
    private:
        std::list<Levels::Level*> levels;
    };
}