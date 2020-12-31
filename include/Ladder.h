#pragma once
#include "StaticObject.h"
class Ladder: public StaticObject
{
public:
	Ladder(
		const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(0, 0),
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr);

	virtual void draw(void (*drawFunc)(const sf::Drawable&)) const override;
	virtual char identify() const override;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	virtual void reset(const sf::Vector2f& )override;

private:
	virtual void setState(const int);
};