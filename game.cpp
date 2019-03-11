#include "game.h"
#include "cstdlib"
#include "time.h"
#include "windows.h"
#include "iostream"

Game::Game(int _width,int _height)
{
    width = _width;
    height = _height;
    window = new sf::RenderWindow(sf::VideoMode(width,height),"Stick Mister",sf::Style::Close);
    window->setFramerateLimit(60);

    init();
}

void Game::init()
{
    loadData();
    srand(time(NULL));
    gameState = startState;
    score = 0;

    backgroundImg.setScale(1 , height / backgroundImg.getLocalBounds().height );

    player = new Player(20,200,30,30,100); // x, y, w, h, v
    object.push_back(player);

    bloc.push_back(new Bloc(0,50));
    bloc.push_back(new Bloc(rand()%150+150,rand()%60+30));
}

void Game::loadData()
{
    backgroundTexture.loadFromFile("data/background.png");
    stickTexture.loadFromFile("data/stick.png");
    backgroundImg.setTexture(backgroundTexture);
    background2Img.setTexture(backgroundTexture);
    stickImg.setTexture(stickTexture);
}

void Game::render()
{
    window->clear();

    window->draw(backgroundImg);
    window->draw(background2Img);

    for(int i=0;i<object.size();i++)
        object[i]->render(window);

    for(int i=0;i<bloc.size();i++)
        bloc[i]->render(window);

    for(int i=0;i<stick.size();i++)
    {
        stickImg.setPosition(stick[i]->position);
        window->draw(stickImg);
    }


    window->display();
}

void Game::update()
{
    for(int i=0;i<object.size();i++)
        object[i]->update(window);

    for(int i=0;i<bloc.size();i++)
        bloc[i]->update(window);

}

void Game::handleEvent()
{
    while(window->pollEvent(event))
        if(event.type == sf::Event::Closed)
            window->close();

    for(int i=0;i<object.size();i++)
        object[i]->handleEvent();

    for(int i=0;i<bloc.size();i++)
        bloc[i]->handleEvent();

    if(gameState == startState)
    {
        while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(gameState == startState)
            {
                gameState = clickState;
                tstick = new Stick();
            }

            if(tstick->height < 230)
            {
                tstick->position.y -= tstick->v;
                tstick->height += tstick->v;

                stickImg.setPosition(tstick->position);
                stickImg.setScale(tstick->width / stickImg.getLocalBounds().width, tstick->height / stickImg.getLocalBounds().height);
                window->draw(stickImg);
                window->display();
            }
        }

        if(gameState == clickState)
        {
            gameState = runState;
            stickImg.setScale(tstick->height / stickImg.getLocalBounds().height, tstick->width / stickImg.getLocalBounds().width);
            tstick->position.x = 50;
            tstick->position.y = 230;
            stick.push_back(tstick);
        }
    }

    if(gameState == runState)
    {
        if(bloc[bloc.size()-1]->position.x <= player->position.x + tstick->height + player->width && bloc[bloc.size()-1]->position.x + bloc[bloc.size()-1]->width >= player->position.x + tstick->height + player->width)
            player->move2d.setVector(player->position, sf::Vector2f(bloc[bloc.size()-1]->position.x + bloc[bloc.size()-1]->width - player->width, 200));

        else
        {
            player->move2d.setVector(player->position, sf::Vector2f(player->position.x + tstick->height + player->width, 200));
            player->isAlive = false;
        }

        player->isDestination = true;
        player->lastUpdateFrameTime = clock();
        player->lastUpdateTime = clock();
        gameState = returnState;
    }

    if(player->isDestination == false && gameState == returnState)
        if(player->isAlive == false)
            gameState = -1, window->close();
        else
            score++;

    if(gameState == returnState)
    {
        if(player->isDestination == false)
        {

                while(player->position.x > 20)
                {
                    bloc[bloc.size()-1]->position.x -= 3;
                    bloc[bloc.size()-2]->position.x -= 3;
                    stick[stick.size()-1]->position.x -= 3;
                    if(stick.size() > 1)
                        stick[stick.size()-2]->position.x -= 3;
                    player->position.x -= 3;

                    backgroundImg.setPosition(backgroundImg.getPosition().x - 0.5,0);
                    background2Img.setPosition(background2Img.getPosition().x - 0.5,0);

                    if(backgroundImg.getPosition().x < backgroundImg.getLocalBounds().width - width)
                        backgroundImg.setPosition(background2Img.getPosition().x + background2Img.getLocalBounds().width,0);

                    render();
                    Sleep(10);
                }

                gameState = addState;

        }
    }

    if(gameState == addState)
    {
        bloc.push_back(new Bloc(380,rand()%50+30));

        bloc[bloc.size()-1]->lastUpdateTime = clock();
        int tempx = rand()%120+100;

        while(bloc[bloc.size()-1]->position.x > tempx)
        {
            bloc[bloc.size()-1]->position.x -= 5;
            render();
            Sleep(10);
        }
        gameState = startState;
    }

}
