#pragma once
#include "StaticObject.h"
class Ladder: public StaticObject
{
public:
	using StaticObject::StaticObject;

	virtual void draw(sf::RenderWindow&)const override;
	//virtual char identify() const override;
	//virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	//virtual void reset(const sf::Vector2f& )override;
	//virtual void addSprite(const sf::Sprite&)override;

private:
	//virtual void setState(const int);
	//virtual void setSprite(const sf::Sprite&);
};