#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class MovingObject;

class Ladder: public StaticObject
{
public:
	Ladder(const sf::Vector2f = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));

	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
private:

};