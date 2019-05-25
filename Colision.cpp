#include <SFML/Graphics.hpp>
#include "Collision.h"
using namespace sf;


bool Collision::checkCollision(RectangleShape & shape1, RectangleShape & shape2) {
    if (shape1.getPosition().x > shape2.getPosition().x-80  &&
        shape1.getPosition().x < shape2.getPosition().x+100 &&
        shape1.getPosition().y > shape2.getPosition().y - 150 ) return true;
    else return false;
}

bool Collision::checkPosition(RectangleShape & shape1, RectangleShape & shape2) {
    if (shape1.getPosition().x > shape2.getPosition().x-80 &&
        shape1.getPosition().x < shape2.getPosition().x+80 &&
        shape1.getPosition().y < shape2.getPosition().y+150 &&
        shape1.getPosition().y < shape2.getPosition().y-150) return true;
    else return false;
}

