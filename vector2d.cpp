#include "vector2d.h"
#include <math.h>

void Vector2d::setVector(sf::Vector2f i,sf::Vector2f f)
{
    punctInitial = i;
    punctFinal = f;
    lungime = sqrt( pow(f.x - i.x, 2) + pow(f.y - i.y, 2) );
    vectorDeplasare = f-i;
    vectorNormalizat = vectorDeplasare / lungime;
}
