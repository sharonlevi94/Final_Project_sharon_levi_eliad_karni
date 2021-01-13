#pragma once
#include "MovingObject.h"
#include "Wall.h"
#include "Board.h"


class Player : public MovingObject
{
public:
	Player(const sf::Vector2f = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));

	virtual void playTurn(const sf::Time&,const Board&) override;
	virtual void handleColision(GameObject&)override;
	virtual void handleColision(Enemy&)override;
	virtual void handleColision(Player&)override;
	int getLives()const;
	void death();
	bool is_alive()const;
private:
	int m_lives;
};