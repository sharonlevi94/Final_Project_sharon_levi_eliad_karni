#pragma once
#include "Enemy.h"
class RandEnemy: public Enemy
{
public:
	RandEnemy(const sf::Vector2f = sf::Vector2f(0, 0),
		const EffectsHolder & = EffectsHolder(),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	virtual void playTurn(const sf::Time&,const Board&) override;

private:
};