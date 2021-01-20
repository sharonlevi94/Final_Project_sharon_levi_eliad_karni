#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class MovingObject;
class Door : public StaticObject
{
public:
	Door(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	virtual ~Door()override = default;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
private:

};
