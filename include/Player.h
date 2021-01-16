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
	void dig(Board&, const sf::Vector2f&);
private:
	std::vector<Wall*> m_diggedWalls;
};