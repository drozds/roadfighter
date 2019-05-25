#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "DrawWindow.h"
#include "Colision.h"
#include <cstdlib>
#include <ctime>

using namespace sf;
using namespace std;

const Vector2f PLAYER_SIZE (100.f, 150.f);
const Color & PLAYER_COLOR = Color::Red;
const float PLAYER_SPEED = 0.2;

const Vector2f ENEMY_SIZE (80.f, 150.f);
const Color & ENEMY_COLOR = Color::Yellow;
const float ENEMY_SPEED = 0.2;

int main()
{   srand(time(NULL));
    Player iam(PLAYER_SIZE, PLAYER_COLOR, PLAYER_SPEED);
    Enemy enemy1(ENEMY_SIZE, ENEMY_COLOR, ENEMY_SPEED);
    Enemy enemy2(ENEMY_SIZE, ENEMY_COLOR, ENEMY_SPEED+0.01);
    Collision collision;
    MyWindow window;
    while (window.myWindow.isOpen())
        {
            Event event;
            while (window.myWindow.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.myWindow.close();
            }
            iam.update();
            float pos1 = rand() % 320;
           float pos2 = rand() % 320;

            //while (collision.checkCollision(enemy1.car, enemy2.car) && pos1 > pos2 - 80 && pos1 < pos2 +80) {
             //   pos2 = rand()% 320;
           // }
            enemy1.update(pos1);
            enemy2.update(pos2);
            if ( collision.checkPosition(enemy1.car, enemy2.car) ) pos2 = rand()%320;

            window.myWindow.clear();
            window.drawShape(iam.car);
            window.drawShape(enemy1.car);
            if(collision.checkCollision(enemy1.car, iam.car)) {
                window.myWindow.clear();
            }

            window.drawShape(enemy2.car);
            window.myWindow.display();
        }

    return 0;
}
