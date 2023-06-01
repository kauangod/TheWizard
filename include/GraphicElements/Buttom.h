#pragma once
#include "../Being.h"
#include <string>

namespace GraphicElements
{
    class Buttom : public Being
    {
    public:
        Buttom(sf::Vector2f pos, unsigned int size, const std::string text);
        ~Buttom();
        void Draw();
        void Update();
        void Selected();
        void UnSelected();
    private:
        sf::Vector2f Position;
        sf::Text text;
        sf::Font f;
    };
}