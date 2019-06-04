#include "GameScore.h"
#include <SFML/Graphics.hpp>
using namespace sf;

GameStatus::GameStatus() {
    gameStatus = false;
}

bool GameStatus::gameStart() {
    if(Keyboard::isKeyPressed(Keyboard::Enter)) {
        gameStatus = true;
        return gameStatus;
    }
}
