#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
using namespace sf;


class Game {

    public:
    Game();
    int score = 0;
    bool gameOn;
    void initMenu();
    void drawAll();
    void updateAll();
};

#endif
