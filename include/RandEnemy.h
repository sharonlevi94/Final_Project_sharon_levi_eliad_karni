#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
class RandEnemy: public Enemy
{
public:
	RandEnemy(const sf::Vector2f = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	virtual void playTurn(const sf::Time&, Board&) override;

private:
	sf::Time m_randTime;
	int m_rand_move;
};