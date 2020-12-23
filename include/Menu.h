#pragma once
#include <SFML/Graphics.hpp>
class Menu
{
public:
	Menu();
	~Menu();

	void draw();
	char handleClick();
	void close();

private:
	sf::Vector2f size;
	sf::Vector2f location;
};

Menu::Menu()
{
}

Menu::~Menu()
{
}