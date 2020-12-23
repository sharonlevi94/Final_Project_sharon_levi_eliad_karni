#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall();
	virtual void draw() const;
	virtual char identify()const;
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);
	virtual int getState()const;

private:
	virtual void setState(const int);
	virtual void setSprite(const sf::Sprite&);
};
