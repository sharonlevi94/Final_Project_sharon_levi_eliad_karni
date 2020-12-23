#pragma once
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
class Enemy: public MovingObject
{
public:
	Enemy();
	virtual void draw() const;
	virtual char identify()const;
	virtual void reset(const sf::Vector2f&);
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void fall();

private:
	 
};