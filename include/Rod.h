#pragma once
#include "StaticObject.h"

class Rod : public StaticObject
{
public:
	Rod(const sf::Vector2f location = sf::Vector2f(0,0), 
		const sf::Vector2f size = sf::Vector2f(OBJ_WIDTH, OBJ_HEIGHT), 
		int state = STAND,
		const sf::Sprite& (*)(char) = nullptr,
		char type = '\0');

	virtual sf::Drawable draw()const override;
//	virtual char identify() const override;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	virtual void reset(const sf::Vector2f& )override;
	virtual void addSprite(const sf::Sprite&)override;

private:
	virtual void setState(const int);
	virtual void setSprite(const sf::Sprite&);
};
