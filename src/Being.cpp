#include "../include/Being.h"
#include <iostream>

Being::Being(ID _id) : 
	id(_id)
{
}

Being::~Being()
{
}

const ID Being::getID() const
{
	return id;
}

Managers::GraphicManager* Being::pGM(Managers::GraphicManager::getInstance());