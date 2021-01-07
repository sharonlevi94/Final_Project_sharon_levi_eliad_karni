#pragma once
#include "MovingObject.h"
#include "Wall.h"
#include "Board.h"

class Player : public MovingObject
{
public:
	Player(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

	//virtual void draw(sf::RenderWindow& window) const;
	virtual void playTurn() override;
	void playTurn(const Board&);
	//void dig(Wall&);

private:
};