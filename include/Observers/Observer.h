#pragma once
#include <string>

namespace Observers
{
    class Observer
    {
    public:
        Observer();
        virtual ~Observer();
        virtual void notifyKeyPressed(std::string key) = 0;
        virtual void notifyKeyReleased(std::string key) = 0;
        //virtual void notifyPlayerDeath();
    protected:
    };
}