#include "../include/GraphicElements/Animation.h"

GraphicElements::Animation::Animation()
{
}

GraphicElements::Animation::~Animation()
{
}

void GraphicElements::Animation::Draw()
{
    pGM->Draw(HitBox);
}

Managers::GraphicManager* GraphicElements::Animation::pGM(Managers::GraphicManager::getInstance());

