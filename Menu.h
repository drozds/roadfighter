#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
private:
	int selectedItemIndex;
	sf::Font font;


};

#endif
