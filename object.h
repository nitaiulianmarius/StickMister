#ifndef OBJECT_H
#define OBJECT_H

class Object
{

    public:

    sf::Vector2f position;

    virtual void render(sf::RenderWindow*&) = 0;
    virtual void update(sf::RenderWindow*) = 0;
    virtual void handleEvent() = 0;
    virtual void loadData() = 0;

    bool isDestination;
    int width,height;
    int lastUpdateTime;
    int lastUpdateFrameTime;
    int defaultUpdateFrameTime;
    int currentFrame;
    int v;
    std::vector<sf::Sprite> animation;


};

#endif OBJECT_H
