#include <SFML/Graphics.hpp>
#include "DrawWindow.h"
#include "Car.h"
#include <string>
using namespace sf;
using namespace std;

const unsigned int WINDOW_WIDTH = 600;
const unsigned int WINDOW_HEIGHT = 600;
string TITLE = "Road Fighter";


RenderWindow MyWindow::myWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE);

//void MyWindow::drawShape(RectangleShape & shape) {
//    myWindow.draw(shape);
//}



