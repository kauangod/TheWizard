#pragma once
#include "Animation.h"
namespace GraphicElements
{
    class SimpleAnimation
    {
    public:
        SimpleAnimation(const char* path, const sf::Vector2u imageCount, const float switchTime);
        ~SimpleAnimation();
        void Update(sf::Vector2f Position, bool faceRight);
        void Reset();
        sf::Texture* getTexture();
        sf::IntRect getSize() const;
    private:
        sf::IntRect uvRect;
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
        sf::Texture* texture;
        sf::RectangleShape HitBox;
    };
}