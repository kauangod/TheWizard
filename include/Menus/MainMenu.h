#pragma once
#include "Menu.h"
#include "../Observers/MenuObserver.h"
#include "../States/State.h"

namespace Menus
{
    class MainMenu: public Menu, public States::State
    {
    public:
        MainMenu(States::StateMachine* pSM, Managers::InputManager* pIM);
        ~MainMenu();
        void Select();
        void Draw();
        void Update();
        void MoveUp();
        void MoveDown();
        void PushButtom(GraphicElements::Buttom* buttom);
    private:
        Observers::MenuObserver* pMObserver;
        Managers::InputManager* pIM;
        //sf::Image background;
    };
}