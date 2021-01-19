#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
class Ladder: public StaticObject
{
public:
	Ladder(const sf::Vector2f = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
private:

};