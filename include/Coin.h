#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "CollectableObject.h"

class Coin: public CollectableObject
{
public:
	Coin(const sf::Vector2f = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
	virtual ~Coin()override;
	
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	static unsigned int getCoinsCounter();
	virtual void reset()override;
	virtual void collect()override;
private:
	static unsigned int m_coinsCounter;
};