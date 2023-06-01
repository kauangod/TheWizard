#include "../include/Menus/PauseMenu.h"

Menus::PauseMenu::PauseMenu(States::StateMachine *pSM, Managers::InputManager *pIM):
    Menu(),
    State(pSM, States::stateID::pauseMenu),
    pMObserver(new Observers::MenuObserver(static_cast<Menus::Menu*>(this))),
    pIM(pIM)
{
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,-30), 30, "Resume"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,0), 30, "Save Game"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,30), 30, "Main Menu"));
    buttons[currentButtom]->Selected();
    pIM->addObserver(static_cast<Observers::Observer*>(pMObserver));

}

Menus::PauseMenu::~PauseMenu()
{
    delete pMObserver;
    pIM->removeObserver(static_cast<Observers::Observer*>(pMObserver));
    pIM = NULL;
}

void Menus::PauseMenu::Select()
{
    if(!this->getIsRunning())
        return;
    switch (currentButtom)
    {
    case 0:
        changeState(previousState->getStateID());
        break;

    case 1:
        static_cast<Levels::Level*>(States::State::previousState)->SaveLevel();
        break;

    case 2:
        changeState(States::stateID::mainMenu);
        break;

    default:
        break;
    }
}

void Menus::PauseMenu::Draw()
{
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Draw();
    }
}

void Menus::PauseMenu::Update()
{
    isRunning = true;
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Update();
    }
}

void Menus::PauseMenu::MoveUp()
{
    if(!this->getIsRunning())
        return;
    if(currentButtom <= 0)
        return;
    buttons[currentButtom--]->UnSelected();
    buttons[currentButtom]->Selected();
}

void Menus::PauseMenu::MoveDown()
{
    if(!this->getIsRunning())
        return;
    if(currentButtom >= (buttomCont - 1))
        return;
    buttons[currentButtom++]->UnSelected();
    buttons[currentButtom]->Selected();
}

void Menus::PauseMenu::PushButtom(GraphicElements::Buttom* buttom)
{
    buttons.push_back(buttom);
    buttomCont++;
}