#pragma once
#include "Gift.h"

class MovingObject;
class TimeGift: public Gift 
{
public:
	TimeGift(const sf::Vector2f = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	void handleColision(vector<std::unique_ptr<RandEnemy>>& giftEnenmy,
		sf::Vector2f doorLoc, GameState& gameState)override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
private:
};
