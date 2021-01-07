#ifndef _COIN_H
#define _COIN_H
#pragma once
#include <SFML/Graphics.hpp>
#include "CollectableObject.h"

class Coin: public CollectableObject
{
public:
	Coin(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));
	
	virtual void          playTurn ()  override;

private:
};
#endif //_COIN_H