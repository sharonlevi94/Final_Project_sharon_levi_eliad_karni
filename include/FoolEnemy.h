#pragma once
#include "Enemy.h"
class FoolEnemy: public Enemy
{
public:
	FoolEnemy();
	
	virtual void fall();
	virtual void draw() const;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);

private:

	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
};