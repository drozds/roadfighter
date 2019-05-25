#ifndef CAR_H
#define CAR_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Car {
    public:
        float xpos, ypos, xvel, yvel;
        RectangleShape car;
};

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
