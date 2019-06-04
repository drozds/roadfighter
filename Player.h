#ifndef PLAYER_H
#define PLAYER_H
#include "Car.h"

class Player: public Car{
    public:
    Player(const Vector2f & size, const Color & color, float speed);
    bool goRight,
         goLeft,
         moveRight(),
         moveLeft();
    void update();
    float step;
};

#endif
