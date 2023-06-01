#include "Obstacle.h"
#include "../Characters/Character.h"
#include "../../GraphicElements/SimpleSprite.h"

namespace Entities
{
	namespace Obstacles
	{

    class Lava: public Obstacle 
    {
    private:
        GraphicElements::SimpleSprite animation;
    public:
        Lava(const sf::Vector2f pos);
        ~Lava();
        void Move();
        void Update();
        void OnCollision(Entities::Entity* ent);
    };
    }
}