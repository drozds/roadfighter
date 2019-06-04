#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "DrawWindow.h"
#include "Colision.h"
#include "GameScore.h"
#include <cstdlib>
#include <ctime>
#include "Game.h"

using namespace sf;
using namespace std;

const Vector2f PLAYER_SIZE (100.f, 150.f);
const Color & PLAYER_COLOR = Color::Red;
const float PLAYER_SPEED = 0.5;

const Vector2f ENEMY_SIZE (80.f, 150.f);
const Color & ENEMY_COLOR = Color::Yellow;
const float ENEMY_SPEED = 0.5;

Game::Game() {

    srand(time(NULL));
}

void Game::drawAll() {
    Player player(PLAYER_SIZE, PLAYER_COLOR, PLAYER_SPEED);
    Enemy enemy1(ENEMY_SIZE, ENEMY_COLOR, ENEMY_SPEED, rand() % 520);
    Enemy enemy2(ENEMY_SIZE, ENEMY_COLOR, ENEMY_SPEED+0.1, rand() % 520);
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
            Font font;
            font.loadFromFile("arial.ttf");
            Text text;
            text.setFont(font);
            text.setString("Press Enter to start");
            text.setColor(Color::White);
            text.setCharacterSize(24);
            text.setPosition(200, 300);

            window.myWindow.clear();
            if(game.gameStatus) {



            if(collision.checkCollision(enemy1.car, player.car) || collision.checkCollision(enemy2.car, player.car)) {
                game.gameStatus = false;
                enemy1.ypos = -150;
                enemy2.ypos = -150;
                enemy1.xpos = rand() % 520;
                enemy2.xpos = rand() % 520;
            }

            window.myWindow.draw(iam.car);
            window.myWindow.draw(enemy1.car);
            window.myWindow.draw(enemy2.car);
            }
            else {
            window.myWindow.draw(text);
            game.gameStart();
            }
                window.myWindow.display();
    }
}

void Game::initGame() {

}

void Game::updateAll() {
    float pos1 = rand() % 520;
    float pos2 = rand() % 520;
    player.update();
    enemy1.update(pos1);
    enemy2.update(pos2);
}
