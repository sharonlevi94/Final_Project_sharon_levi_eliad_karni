#pragma once
#include "MovingObject.h"
#include "Wall.h"
class Player : public MovingObject
{
public:
	Player();

	virtual char identify() const override;
	virtual void draw() const override;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	virtual void reset(const sf::Vector2f&) override;
	void dig(Wall&);

private:

	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
};