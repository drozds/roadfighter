#ifndef COLLISION_H
#define COLLISION_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Collision {
    public:
        bool checkCollision(RectangleShape & shape1, RectangleShape & shape2),
             checkPosition(RectangleShape & shape1, RectangleShape & shape2);
};

#endif // COLLISION_H

