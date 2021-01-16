#pragma once
#include "MovingObject.h"
#include <vector>

class Board;
class Wall;

class Player : public MovingObject
{
public:
	Player(const sf::Vector2f = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));

	virtual void playTurn(const sf::Time&, Board&) override;

private:
	std::vector<Wall*> m_diggedWalls;

	void updateDiggedWalls(const sf::Time& deltaTime);
	void dig(Board&, const sf::Vector2f&, const sf::Time&);
};