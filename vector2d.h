#ifndef VECTOR2D
#define VECTOR2D

#include <SFML/Graphics.hpp>

class Vector2d
{
public:

    void setVector(sf::Vector2f,sf::Vector2f);

    sf::Vector2f punctInitial;
    sf::Vector2f punctFinal;
    sf::Vector2f vectorDeplasare;
    sf::Vector2f vectorNormalizat;
    float lungime;

};

#endif // VECTOR2D
