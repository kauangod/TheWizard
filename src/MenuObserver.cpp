#include "../include/Observers/MenuObserver.h"

Observers::MenuObserver::MenuObserver(Menus::Menu* menu)
{
    this->menu = menu;
    inputSets["Up"] = "W";
    inputSets["Down"] = "S";
    inputSets["Select"] = "Enter";
}

Observers::MenuObserver::~MenuObserver()
{
}

void Observers::MenuObserver::notifyKeyPressed(std::string key)
{
    mapIt = inputSets.begin();
    for (mapIt; mapIt != inputSets.end(); mapIt++)
	{
		if (mapIt->second == key)
		{
			if( mapIt->first == "Up")
            {
                menu->MoveUp();
                return;
            }
            if( mapIt->first == "Down")
            {
                menu->MoveDown();
                return;
            }
            if(mapIt->first == "Select")
            {
                menu->Select();
                return;
            }
		}
    }
}

void Observers::MenuObserver::notifyKeyReleased(std::string key)
{
}