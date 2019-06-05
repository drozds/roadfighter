#include <SFML/Graphics.hpp>
#include "Colision.h"
#include <ctime>
#include <cstdlib>

using namespace sf;


bool Collision::checkCollision(RectangleShape & shape1, RectangleShape & shape2) {
    if (shape1.getPosition().x > shape2.getPosition().x-80  &&
        shape1.getPosition().x < shape2.getPosition().x+100 &&
        shape1.getPosition().y > shape2.getPosition().y - 150 ) return true;
    else return false;
}

float Collision::checkXPositions(float x1, float x2) {
    srand(time(NULL));
    do {
        x2 = rand() % 520;
    } while (x2 >= x1 - 80 && x2 <= x1 + 80 );
    return x2;
}

