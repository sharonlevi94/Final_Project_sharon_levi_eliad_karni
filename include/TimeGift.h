#pragma once
#include "Gift.h"

class MovingObject;
class Controller;

class TimeGift: public Gift 
{
public:
	TimeGift(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	void handleColision(Controller&)override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
private:
};
