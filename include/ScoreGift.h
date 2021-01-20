#pragma once
#include "Gift.h"

class Controller;
class ScoreGift : public Gift
{
public:
	ScoreGift(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	virtual void handleColision(Controller&) override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
private:
};
