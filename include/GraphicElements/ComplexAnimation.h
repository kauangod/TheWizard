#pragma once
#include "Animation.h"
#include "SimpleAnimation.h"
#include <map>

namespace GraphicElements
{
    enum Animation_ID
    {
        idle =   0,
        walk =   1,
        jump =   2,
        attack = 3,
        hurt   = 4,
        death  = 5
    };

    class ComplexAnimation : public Animation
    {
    public:
        ComplexAnimation();

        ~ComplexAnimation();

        void pushAnimation(Animation_ID id, const char* path, sf::Vector2u imageCount, const float switchTime = 0.2f);

        void Update(Animation_ID id, sf::Vector2f position, bool faceRight);

    private:
        std::map<Animation_ID, SimpleAnimation*> animationMap;
        Animation_ID currentAnimation;
    };
}