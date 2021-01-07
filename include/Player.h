#pragma once
#include "MovingObject.h"
#include "Wall.h"

class Player : public MovingObject
{
public:
	Player(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

	//virtual void draw(sf::RenderWindow& window) const;
	virtual void playTurn(const Board&) override;
	//void dig(Wall&);

private:
};