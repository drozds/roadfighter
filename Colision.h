#ifndef COLLISION_H
#define COLLISION_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Collision {
    public:
        bool checkCollision(RectangleShape & shape1, RectangleShape & shape2);
        float checkXPositions(float x1, float x2);
};

#endif // COLLISION_H

