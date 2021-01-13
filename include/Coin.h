#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "CollectableObject.h"

class Coin: public CollectableObject
{
public:
	Coin(const sf::Vector2f = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
	~Coin();
	
	static unsigned int getCoinsCounter();
	virtual void playTurn(const sf::Time&, const Board&)override;
private:
	static unsigned int m_coinsCounter;
};