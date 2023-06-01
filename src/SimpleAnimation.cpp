#include "../include/GraphicElements/SimpleAnimation.h"

GraphicElements::SimpleAnimation::SimpleAnimation(const char* path, const sf::Vector2u imageCount, const float switchTime):
    imageCount(imageCount),
    switchTime(switchTime),
    currentImage(0,0),
    texture(Managers::GraphicManager::getInstance()->loadTexture(path))
{
    uvRect.width = texture->getSize().x / static_cast<float>(imageCount.x);
    uvRect.height = texture->getSize().y;
}

GraphicElements::SimpleAnimation::~SimpleAnimation()
{
}

void GraphicElements::SimpleAnimation::Update(sf::Vector2f Position, bool faceRight)
{

    totalTime += Managers::GraphicManager::getDeltaTime();
    
    if(totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        
        if(currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }

    uvRect.left = currentImage.x * uvRect.width;

    HitBox.setPosition(Position);

    if(faceRight)
    {
        uvRect.left = (currentImage.x) * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }

}


void GraphicElements::SimpleAnimation::Reset()
{
    currentImage.x = 0;
    totalTime = 0;
}

sf::Texture* GraphicElements::SimpleAnimation::getTexture() {return texture;}

sf::IntRect GraphicElements::SimpleAnimation::getSize() const {return uvRect;}
