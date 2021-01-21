#pragma once
#include "Enemy.h"

class FoolEnemy: public Enemy
{
public:
	FoolEnemy(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	
	virtual void playTurn(const sf::Time&, Board&)override;
	virtual void handleCollision(Wall&, const sf::Vector2f&)override;
private:
	bool m_turn;
};