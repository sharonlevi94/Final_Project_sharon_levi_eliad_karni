#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "CollectableObject.h"
using std::vector;

class Coin: public CollectableObject
{
public:
	Coin(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));
	
	virtual void          playTurn (const Board&)  override;

private:

	//virtual void        collect () override;
	//virtual void        setState (const int)  override;
	//virtual void        setLocation (const sf::Vector2f&) override;
	//virtual void        setSprite  (const sf::Sprite&) override;
};