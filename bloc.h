#ifndef BLOC_H
#define BLOC_H

#include "SFML/Graphics.hpp"
#include "object.h"
#include "vector2d.h"

class Bloc:public Object
{
public:
    Bloc(int x, int _width);
    void render(sf::RenderWindow*&);
    void update(sf::RenderWindow*);
    void handleEvent();
    void loadData();

    sf::Texture blocTexture;
    sf::Sprite blocImg;

    Vector2d move2d;
};

#endif
