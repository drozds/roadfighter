#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "DrawWindow.h"
#include "Colision.h"
#include "GameScore.h"
#include "Car.h"
using namespace sf;
using namespace std;


class Game {

    public:
    Game();
    bool gameOn;
    void initGame();
    void drawAll();
    void updateAll();

};

#endif
