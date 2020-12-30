#pragma once
#include "Enemy.h"
class SmartEnemy: public Enemy
{
public:
	SmartEnemy();

	virtual void draw(void (*drawFunc)(const sf::Drawable&)) const override;
	virtual char identify() const override;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	virtual void reset(const sf::Vector2f&) override;

private:

	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
};