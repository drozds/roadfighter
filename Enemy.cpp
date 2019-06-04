#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace sf;
using namespace std;

Enemy::Enemy(const Vector2f & size, const Color & color, float speed, float xposition) {

    xvel = 0;
    yvel = speed;
    car.setPosition(this->xpos, this->ypos);
    car.setFillColor(color);
    car.setSize(size);
    xpos = xposition;
    ypos = -150;
}

void Enemy::update(float xposition) {

    if(ypos<650) {
    ypos += yvel;
    car.setPosition(xpos, ypos);
    }
    else  {
        xpos = xposition;
        ypos = -150;
        //cout<<++score<<endl;;
    }

}
