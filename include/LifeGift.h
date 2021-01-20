#pragma once
#include "Gift.h"

class Controller;


class LifeGift : public Gift
{
public:
	LifeGift(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	virtual void handleColision(Controller&) override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
private:
};
