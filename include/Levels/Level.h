#pragma once
//#include <vector>
#include "../Managers/CollisionManager.h"
#include "../Managers/EventsManager.h"
#include "../Math/List.h"// remover se a classe EntityList funcionar (e estiver corretamente implementado)
#include "../Math/EntityList.h"
#include "../Entities/Characters/Player.h"
#include "../Entities/Arrow.h"
#include "../Entities/Characters/Enemies/Warrior.h"
#include "../Entities/Characters/Enemies/Archer.h"
#include "../Entities/Characters/Enemies/Warrior.h"
#include "../Entities/Obstacles/Ground.h"
#include "../Entities/Obstacles/Lava.h"
#include "../States/State.h"
#include "../Observers/PlayerInputManager.h"
#include "../GraphicElements/Buttom.h"

namespace Levels
{
    class Level: public Being, public States::State
    {
    public:
        Level(const ID id = ID::level, States::StateMachine* pSM = NULL, Managers::InputManager* pIM = NULL);
        virtual ~Level();
        virtual void Draw();
        virtual void Update();
        void CreateWarrior(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreatePlayer(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreateGround(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreateLava(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreateArcher(const sf::Vector2f pos = sf::Vector2f(0, 0));
        virtual void CreateMap() = 0;
        void CreateEntity(char id, sf::Vector2f pos);
        Observers::PlayerInputManager* getPlayerInputManager() const;
        void SaveLevel();
        void LoadLevel();
        void Reset();
        bool getLevelStarted() const;
    protected:
        bool                                levelStarted;
    	Managers::InputManager*             pIM;
        Observers::PlayerInputManager*      pPIM;
        Entities::Characters::Player*       pPlayer;
        Entities::Characters::Player*       pPlayer2;
        Managers::CollisionManager*         pCManager;
        Math::EntityTList                   SentitiesList;
        //Math::EntityTList                   DentitiesList;
	    Math::EntityList		            DentitiesList;
    };
}
