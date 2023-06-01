#include "../include/Menus/Menu.h"

Menus::Menu::Menu():
    Being(ID::menu),
    currentButtom(0),
    buttomCont(0)
{
}

Menus::Menu::~Menu()
{
    /*for(int i = 0; i < buttomCont; i++)
    {
        if(buttons[i])
            delete buttons[i];
    }
    buttons.clear();
    /* */
}
/*
void Menus::Menu::MoveUp()
{
    if()
    if(currentButtom <= 0)
        return;
    buttons[currentButtom--]->UnSelected();
    buttons[currentButtom]->Selected();
}

void Menus::Menu::MoveDown()
{
    if(currentButtom >= (buttomCont - 1))
        return;
    buttons[currentButtom++]->UnSelected();
    buttons[currentButtom]->Selected();
}

void Menus::Menu::PushButtom(GraphicElements::Buttom* buttom)
{
    buttons.push_back(buttom);
    buttomCont++;
}
/* */