#pragma once
#include <SFML/Graphics.hpp>
#include <EffectsHolder.h>
class Menu
{
public:
	Menu(
		const sf::Vector2f& size = sf::Vector2f(800,600),
		const sf::Vector2f& location = sf::Vector2f(0,0));

	void draw(sf::RenderWindow& window);
	char handleClick();
	void close();

private:
	sf::Vector2f m_size;
	sf::Vector2f m_location;
	EffectsHolder temp_effects;

};