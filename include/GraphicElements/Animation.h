#pragma once
#include <SFML/Graphics.hpp>
#include "../Managers/GraphicManager.h"
#include "../Being.h"

namespace GraphicElements
{
    class Animation
    {
    public:
        Animation();
        virtual ~Animation();
        virtual void Draw();
    protected:
        static Managers::GraphicManager* pGM;
        sf::RectangleShape HitBox;
    };
}