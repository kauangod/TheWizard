#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include <string.h>

#define WIDTH 1280
#define HEIGHT 768

namespace Managers
{
    class GraphicManager
    {
    public:
        ~GraphicManager();
        static GraphicManager* getInstance();
        void Draw(sf::RectangleShape &hitbox);
        void Draw(sf::Text &text);
        sf::RenderWindow* getWindow();
        sf::Vector2f getViewCenter() const;
        void Close();
        void Display();
        void Clear();
        const bool isWindowOpen() const;
        void CenterView(sf::Vector2f pos);
        static void updateDeltaTime();
        static float getDeltaTime();
        sf::Texture* loadTexture(const char* path);
    private:
        GraphicManager();
        static GraphicManager* Instance;
        sf::RenderWindow window;
        sf::View view;
        static sf::Clock clock;
        static float dt;
        sf::ContextSettings settings;
        std::map<const char*, sf::Texture*> textureMap;
    };
}