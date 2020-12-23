#pragma once
#include "GameObject.h"
class MovingObject : public GameObject
{
public:
	MovingObject();
	virtual void draw() const;
	virtual char identify()const;
	virtual void reset(const sf::Vector2f&);
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void fall();

private:
	
};