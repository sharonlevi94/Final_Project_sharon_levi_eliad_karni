#pragma once
#include "MovingObject.h"
#include "Wall.h"

class Player : public MovingObject
{
public:
	Player(const sf::Vector2f& location = sf::Vector2f(0, 0),
		const EffectsHolder& effects = EffectsHolder());

	virtual void draw(sf::RenderWindow& window) const;
	virtual void playTurn() override;
 void playTurn(const sf::Vector2f&);
	//void dig(Wall&);

private:
};