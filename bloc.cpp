#include "bloc.h"

Bloc::Bloc(int x, int _width)
{
    v = 160;
    position.x = x;
    position.y = 230;
    width = _width;

    loadData();
    blocImg.setScale(width / blocImg.getLocalBounds().width, 1);
}

void Bloc::render(sf::RenderWindow*& window)
{
    blocImg.setPosition(position);
    window->draw(blocImg);
}

void Bloc::update(sf::RenderWindow* window)
{

}

void Bloc::handleEvent()
{

}

void Bloc::loadData()
{
    blocTexture.loadFromFile("data/bloc.png");
    blocImg.setTexture(blocTexture);
}
