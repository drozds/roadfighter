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
#include "Menu.h"
#include <string>
#include <fstream>

using namespace sf;
using namespace std;

const Vector2f PLAYER_SIZE (100.f, 150.f);
const Color & PLAYER_COLOR = Color::Red;
const float PLAYER_SPEED = 0.25;

const Vector2f ENEMY_SIZE (80.f, 150.f);
const Color & ENEMY_COLOR = Color::Yellow;
const float ENEMY_SPEED = 0.2;

Game::Game() {
    gameOn = false;
    srand(time(NULL));

}

void Game::drawAll() {
    Player *player = new Player(PLAYER_SIZE, PLAYER_COLOR, PLAYER_SPEED);
    Enemy *enemy1 = new Enemy(ENEMY_SIZE, ENEMY_COLOR, ENEMY_SPEED, rand() % 180);
    Enemy *enemy2 = new Enemy(ENEMY_SIZE, ENEMY_COLOR, ENEMY_SPEED+0.05, rand() % 180 + 260);
    Collision *collision = new Collision;
    MyWindow *window = new MyWindow;
    Menu * menu = new Menu(window->myWindow.getSize().x, window->myWindow.getSize().y);
    /*
    ifstream readFile;
    readFile.open("Highscore.txt");
    if ( readFile.is_open() ) {
        while ( readFile.eof() ) {
            readFile >> menu->bestScore;
        }
    }
    readFile.close();

    ofstream writeFile( "Highscore.txt");
    if (writeFile.is_open() ) {
        if ( score > menu->bestScore) {
            menu->bestScore = score;
        }
        writeFile << menu->bestScore;

    }
    writeFile.close();
*/

    while (window->myWindow.isOpen())
        {
            Event event;
            while (window->myWindow.pollEvent(event))
            {

                if (event.type == Event::Closed)
                    window->myWindow.close();
            }

            window->myWindow.clear();

            score = enemy1->times + enemy2->times;

            if( !gameOn ) {
                if(Event::KeyReleased){
                switch (event.key.code)
                    {
                        case Keyboard::Up:
                            menu->MoveUp();
                            break;

                        case Keyboard::Down:
                            menu->MoveDown();
                            break;

                        case Keyboard::Return:
                            switch (menu->GetPressedItem())
                            {
                                case 0:
                                    gameOn = true;
                                    break;
                                case 1:
                                    window->myWindow.close();
                                    break;
                            }

                            break;
                    }
                }


                menu->draw(window->myWindow);

            }
            else {
                if(collision->checkCollision(enemy1->car, player->car) || collision->checkCollision(enemy2->car, player->car)) {

                    enemy1->times = 0;
                    enemy2->times = 0;
                    menu->menu[2].setString("Score " + to_string(score));
                    score = 0;
                    gameOn = false;
                    enemy1->ypos = -150;
                    enemy2->ypos = -150;
                    enemy1->xpos = rand() % 520;
                    collision->checkXPositions(enemy1->xpos, enemy2->xpos);
                }
                float pos1 = 0;
                float pos2 = 0;
                pos2 = collision->checkXPositions(pos1, pos2);
                pos1 = collision->checkXPositions(pos2, pos1);


                player->update();
                enemy1->update(pos1);
                enemy2->update(pos2);
                window->myWindow.draw(player->car);
                window->myWindow.draw(enemy1->car);
                window->myWindow.draw(enemy2->car);
            }
            window->myWindow.display();
        }
    delete menu;
    delete player;
    delete window;
    delete collision;
    delete enemy1;
    delete enemy2;
}



