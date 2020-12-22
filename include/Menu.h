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
	sf::Vector2f m_size;
	sf::Vector2f m_location;
};