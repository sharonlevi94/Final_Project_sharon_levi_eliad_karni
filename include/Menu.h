#pragma once
#include <SFML/Graphics.hpp>
class Menu
{
public:
	Menu();
	~Menu();
	void draw();
	char handleClick();

private:
	sf::Vector2f size;
	sf::Vector2f location;
};