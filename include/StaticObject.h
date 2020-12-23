#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class StaticObject : public GameObject
{
public:
	StaticObject();
	virtual void draw();
	virtual char identify()const;
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);
	

private:
	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
	virtual void setSprite(const sf::Sprite&);
};
