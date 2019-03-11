#include "player.h"
#include "time.h"

Player::Player(int x, int y, int w, int h, int _v)
{
    loadData();
    position.x = x;
    position.y = y;
    width = w;
    height = h;
    v = _v;
    isAlive = true;
    isDestination = false;
    currentFrame = 0;
    defaultUpdateFrameTime = 100;

    playerImg.setTextureRect(sf::IntRect(0,128,128,128));
    playerImg.setScale(width / playerImg.getLocalBounds().width , height / playerImg.getLocalBounds().height);
    animation.push_back(playerImg);
    playerImg.setTextureRect(sf::IntRect(128,128,128,128));
    animation.push_back(playerImg);
    playerImg.setTextureRect(sf::IntRect(256,128,128,128));
    animation.push_back(playerImg);
    playerImg.setTextureRect(sf::IntRect(384,128,128,128));
    animation.push_back(playerImg);
}

void Player::render(sf::RenderWindow*& window)
{
    animation[currentFrame].setPosition(position);
    window->draw(animation[currentFrame]);
}

void Player::update(sf::RenderWindow* window)
{
    if(isDestination)
    {
        position.x += v * (clock() - lastUpdateTime)/1000.;
        lastUpdateTime = clock();

        if(move2d.punctFinal.x - position.x < 2)
        {
            isDestination = false;
            currentFrame = 0;
        }

        if(clock() - lastUpdateFrameTime > defaultUpdateFrameTime)
        {
            currentFrame++;
            if(currentFrame >= animation.size())
                currentFrame = 0;
            lastUpdateFrameTime = clock();
        }
    }
}

void Player::handleEvent()
{
    /*
    isDestination = true;
    lastUpdateTime = clock();
    lastUpdateFrameTime = clock();
    move2d.setVector(position,sf::Vector2f(xMouse,yMouse));
    */
}

void Player::loadData()
{
    playerTexture.loadFromFile("data/player.png");
    playerImg.setTexture(playerTexture);
}
