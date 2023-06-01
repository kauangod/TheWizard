#include "../include/Managers/InputManager.h"

Managers::InputManager::InputManager()
{
    subObservers.clear();
    keyMap.clear();
	keyMap[sf::Keyboard::A] = 'A';
	keyMap[sf::Keyboard::B] = 'B';
	keyMap[sf::Keyboard::C] = 'C';
	keyMap[sf::Keyboard::D] = 'D';
	keyMap[sf::Keyboard::E] = 'E';
	keyMap[sf::Keyboard::F] = 'F';
	keyMap[sf::Keyboard::G] = 'G';
	keyMap[sf::Keyboard::H] = 'H';
	keyMap[sf::Keyboard::I] = 'I';
	keyMap[sf::Keyboard::J] = 'J';
	keyMap[sf::Keyboard::K] = 'K';
	keyMap[sf::Keyboard::L] = 'L';
	keyMap[sf::Keyboard::M] = 'M';
	keyMap[sf::Keyboard::N] = 'N';
	keyMap[sf::Keyboard::O] = 'O';
	keyMap[sf::Keyboard::P] = 'P';
	keyMap[sf::Keyboard::Q] = 'Q';
	keyMap[sf::Keyboard::R] = 'R';
	keyMap[sf::Keyboard::S] = 'S';
	keyMap[sf::Keyboard::T] = 'T';
	keyMap[sf::Keyboard::U] = 'U';
	keyMap[sf::Keyboard::V] = 'V';
	keyMap[sf::Keyboard::W] = 'W';
	keyMap[sf::Keyboard::X] = 'X';
	keyMap[sf::Keyboard::Y] = 'Y';
	keyMap[sf::Keyboard::Z] = 'Z';
	keyMap[sf::Keyboard::Enter] = "Enter";
	keyMap[sf::Keyboard::LShift] = "LShift";
	keyMap[sf::Keyboard::Space] = "Space";
	keyMap[sf::Keyboard::LControl] = "lCtrl";
	keyMap[sf::Keyboard::RControl] = "rCtrl";
	keyMap[sf::Keyboard::Tab] = "Tab";
	keyMap[sf::Keyboard::Escape] = "Esc";
	keyMap[sf::Keyboard::Right] = "Right";
	keyMap[sf::Keyboard::Left] = "Left";
	keyMap[sf::Keyboard::Up] = "Up";
	keyMap[sf::Keyboard::Down] = "Down";
	mapIt = keyMap.begin();
}

Managers::InputManager::~InputManager()
{
    subObservers.clear();
    keyMap.clear();
}

void Managers::InputManager::pressedInput(sf::Event::KeyEvent key)
{
    listIt = subObservers.begin();
    for(listIt; listIt != subObservers.end(); listIt++)
    {
        (*listIt)->notifyKeyPressed(keyMap[key.code]);
    }
}

void Managers::InputManager::releasedInput(sf::Event::KeyEvent key)
{
    listIt = subObservers.begin();
    for(listIt; listIt != subObservers.end(); listIt++)
    {
        (*listIt)->notifyKeyReleased(keyMap[key.code]);
    }
}

void Managers::InputManager::addObserver(Observers::Observer* observer)
{
    if(observer)
        subObservers.push_back(observer);
}

void Managers::InputManager::removeObserver(Observers::Observer* observer)
{
    listIt = subObservers.begin();
    for(listIt; listIt != subObservers.end(); listIt++)
    {
        if((*listIt) == observer)
			subObservers.erase(listIt);
    }
}