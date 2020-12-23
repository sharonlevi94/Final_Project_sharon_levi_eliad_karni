#pragma once
#include "MovingObject.h"
class Player : public MovingObject
{
public:
	Player();
	virtual void draw() const;
	virtual char identify()const;
	virtual void reset(const sf::Vector2f&);
	virtual void playTurn(char (*)(const sf::Vector2f&));
	int receive_command()const;
	virtual void fall();

private:
	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
	virtual void setSprite(const sf::Sprite&);
};