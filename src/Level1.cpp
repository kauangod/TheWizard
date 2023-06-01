#include "../include/Levels/Level1.h"

Levels::Level1::Level1(States::StateMachine* pSM, Managers::InputManager* pIM) : 
    Level(ID::level1, pSM, pIM)
{
    CreateMap();
    pCManager->setDList(DentitiesList.getTList());
    pCManager->setSList(SentitiesList);
}

Levels::Level1::~Level1()
{
}

void Levels::Level1::CreateMap()
{
    //std::cout<< "create map" << std::endl;
    std::ifstream Map;
    std::string str;
    int j = 0;
    Map.open("Assets/Level1.txt");
    //std::cout<< "Open map" << std::endl;
    if (!Map.is_open())
    {
        std::cout << "ERROR: Failed to Open 'Level1.txt'" << std::endl;
        exit(1);
    }

    while (std::getline(Map, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
            {
                //std::cout<< "create entity" << std::endl;
                CreateEntity(str[i], sf::Vector2f(i, j));
            }
        }
        j++;
    }
    Map.close();
}
