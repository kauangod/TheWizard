#pragma once
#include "Animation.h"
namespace GraphicElements
{
    class SimpleSprite : public Animation
    {
    public:
        SimpleSprite();
        ~SimpleSprite();    
        void Update(sf::Vector2f Position);
        void Reset(const char* path, sf::Vector2f position, sf::Vector2f size);
    private:
        sf::Texture* texture;
    };
}