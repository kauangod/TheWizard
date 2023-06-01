#include "../include/GraphicElements/ComplexAnimation.h"


GraphicElements::ComplexAnimation::ComplexAnimation()
{
}

GraphicElements::ComplexAnimation::~ComplexAnimation()
{
    std::map<Animation_ID, SimpleAnimation*>::iterator it;
    for (it = animationMap.begin(); it != animationMap.end(); it++)
    {
        if(it->second)
            delete (it->second);
    }

    animationMap.clear();
}

void GraphicElements::ComplexAnimation::pushAnimation(Animation_ID id, const char* path, sf::Vector2u imageCount, const float switchTime)
{
    animationMap[id] = new SimpleAnimation(path, imageCount, switchTime);
    if(!animationMap[id])
    {
        std::cout << "ERROR: Failed To Memory Allocate" << std::endl;
        exit(1);
    }

    HitBox.setSize(sf::Vector2f(static_cast<float>(animationMap[id]->getSize().width), static_cast<float>(animationMap[id]->getSize().height)));
    HitBox.setOrigin(animationMap[id]->getSize().width/2, 0.75 * animationMap[id]->getSize().height);
}

void GraphicElements::ComplexAnimation::Update(Animation_ID id, sf::Vector2f position, bool faceRight)
{
    if (currentAnimation != id) 
    {
            currentAnimation = id;
            animationMap[currentAnimation]->Reset();
    }

    animationMap[id]->Update(position, faceRight);

    HitBox.setPosition(position);
    HitBox.setTextureRect(animationMap[currentAnimation]->getSize());
    HitBox.setTexture(animationMap[currentAnimation]->getTexture());
}