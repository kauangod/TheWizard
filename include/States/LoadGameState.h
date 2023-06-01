#pragma once

#include "State.h"
#include "../Levels/Level.h"


namespace States
{
    class LoadGameState: public State
    {
    public:
        LoadGameState(States::StateMachine* pSMachine);
        ~LoadGameState();
        void Update();
        void Draw();
        void PushLevel(Levels::Level* level);
    private:
        std::list<Levels::Level*> levels;
    };
}