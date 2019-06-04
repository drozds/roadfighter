#ifndef ENEMY_H
#define ENEMY_H
#include "Car.h"
class Enemy: public Car{
    public:

    Enemy(const Vector2f & size, const Color & color, float speed, float xposition);
    void update(float xposition);
    //int score = 0;
};

#endif // ENEMY_H
