#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Player::Player(const Vector2f & size, const Color & color, float speed) {
    xpos = 250;
    ypos = 450;
    car.setPosition(this->xpos, this->ypos);
    car.setFillColor(color);
    car.setSize(size);
    goRight = false;
    goLeft = false;
    step = speed;
    xvel = 0;
    yvel = 0;
}

bool Player::moveRight() {
    if(Keyboard::isKeyPressed(Keyboard::Right)) {
        this->goRight = true;
        return this->goRight;
    }else {
        this->goRight = false;
        return this->goRight;
    }
}

bool Player::moveLeft() {
    if(Keyboard::isKeyPressed(Keyboard::Left)) {
        this->goLeft = true;
        return this->goLeft;
    }else {
        this->goLeft = false;
        return this->goLeft;
    }
}

void Player::update() {

    if (this->moveRight() && this->moveLeft()) {
        xvel = 0;
    }
    else if(this->moveRight() && xpos < 500) {
        xvel = step;
    }
    else if(this->moveLeft() && xpos > 0){
        xvel = -step;
    }

    else {
        xvel = 0 ;
    }
    xpos += xvel;

    this->car.setPosition(xpos, ypos);
}


