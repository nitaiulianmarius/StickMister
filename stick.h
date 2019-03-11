#ifndef STICK_H
#define STICK_H

#include "SFML/Graphics.hpp"
#include "object.h"
#include "vector2d.h"

class Stick:public Object
{
public:
    Stick();
    void render(sf::RenderWindow*&);
    void update(sf::RenderWindow*);
    void handleEvent();
    void loadData();

    Vector2d move2d;

};

#endif
