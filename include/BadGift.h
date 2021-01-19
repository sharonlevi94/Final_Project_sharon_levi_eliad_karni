#pragma once
#include "Gift.h"
class BadGift : public Gift
{
public:
	BadGift(const sf::Vector2f = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	virtual void handleColision(vector<std::unique_ptr<RandEnemy>>&,
		sf::Vector2f, GameState&) override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
private:
};
