#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "CollectableObject.h"

class Coin: public CollectableObject
{
public:
	Coin(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));
	
	virtual void playTurn(const sf::Time&, const Board&)override;
private:
};