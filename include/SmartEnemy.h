#pragma once
#include "Enemy.h"
class SmartEnemy: public Enemy
{
public:
	SmartEnemy();
	virtual void draw() const;
	virtual char identify()const;
	virtual void reset(const sf::Vector2f&);
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void fall();

private:
	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
	virtual void setSprite(const sf::Sprite&);
};