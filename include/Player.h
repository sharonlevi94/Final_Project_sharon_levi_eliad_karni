#pragma once
#include "MovingObject.h"
#include "Wall.h"
class Player : public MovingObject
{
public:
	Player();

	virtual void draw() const;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);
	void dig(Wall&);

private:

	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
};