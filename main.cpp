#include <iostream>
#include <conio.h>
#include "Game.h"

using namespace std;

int main()
{

    Game *StickHero = new Game(380,320);

    while(StickHero->window->isOpen())
    {
        StickHero->handleEvent();
        StickHero->update();
        StickHero->render();
    }

    std::cout<<"Scorul tau este: "<<StickHero->score;
    getch();

}
