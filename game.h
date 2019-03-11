#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "object.h"
#include "vector"
#include "player.h"
#include "bloc.h"
#include "stick.h"

#define startState 0
#define clickState 1
#define runState 2
#define returnState 3
#define addState 4

class Game
{
    public:

    Game(int,int);
    void init();
    void loadData();
    void render();
    void update();
    void handleEvent();

    int width,height;
    int gameState;
    int score;

    Player *player;
    Stick *tstick;
    std::vector<Bloc*> bloc;
    std::vector<Stick*> stick;
    std::vector<Object*> object;

    sf::RenderWindow *window;
    sf::Event event;
    sf::Texture backgroundTexture,stickTexture;
    sf::Sprite backgroundImg,background2Img,stickImg;

};

#endif
