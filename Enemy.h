#ifndef ENEMY_H
#define ENEMY_H
#include "Car.h"
#include "Game.h"
class Enemy: public Car, public Game{
    public:
    int times = 0;
    Enemy(const Vector2f & size, const Color & color, float speed, float xposition);
    void update(float xposition);
    //int score = 0;
};

#endif // ENEMY_H
