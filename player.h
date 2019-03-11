#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "object.h"
#include "vector2d.h"

class Player:public Object
{
public:
    Player(int, int, int, int, int);
    void render(sf::RenderWindow*&);
    void update(sf::RenderWindow*);
    void handleEvent();
    void loadData();

    bool isAlive;

    sf::Texture playerTexture;
    sf::Sprite playerImg;

    Vector2d move2d;

};

#endif
