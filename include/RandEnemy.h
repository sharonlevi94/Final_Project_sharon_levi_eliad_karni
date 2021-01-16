#pragma once
#include "Enemy.h"
class RandEnemy: public Enemy
{
public:
	RandEnemy(const sf::Vector2f = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	virtual void playTurn(const sf::Time&, Board&) override;

private:
};