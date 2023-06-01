#pragma once
#include "Observer.h"
#include "../Menus/Menu.h"
#include <map>

namespace Observers
{
    class MenuObserver: public Observer
    {
    public:
        MenuObserver(Menus::Menu* menu);
        ~MenuObserver();
        void notifyKeyPressed(std::string key);
        void notifyKeyReleased(std::string key);
    private:
        Menus::Menu* menu;
    	std::map<std::string, std::string> inputSets;
        std::map<std::string, std::string>::iterator mapIt;
    };
}