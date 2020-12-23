#pragma once
#include "MovingObject.h"
class Player : public MovingObject
{
public:
	Player();

	virtual void fall();
	virtual void draw() const;
	virtual char identify()const;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);

private:

	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
	virtual void setSprite(const sf::Sprite&);
};