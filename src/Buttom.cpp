#include "../include/GraphicElements/Buttom.h"

GraphicElements::Buttom::Buttom(sf::Vector2f pos, unsigned int size, const std::string text):
    Being(ID::buttom)
{
    if(!f.loadFromFile("Assets/arial.ttf"))
    {
        std::cout << "ERROR: Failed to load font\n";
        exit(1);
    }
    this->text.setFont(f);
    this->text.setCharacterSize(size);
    this->text.setStyle(sf::Text::Bold);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    Position = pos;
}

GraphicElements::Buttom::~Buttom()
{
}

void GraphicElements::Buttom::Update()
{
    text.setPosition(Position);
    pGM->CenterView(sf::Vector2f(0,0));
}

void GraphicElements::Buttom::Draw()
{
    pGM->Draw(text);
}

void GraphicElements::Buttom::Selected()
{
    text.setFillColor(sf::Color::Red);
}

void GraphicElements::Buttom::UnSelected()
{
    text.setFillColor(sf::Color::White);
}