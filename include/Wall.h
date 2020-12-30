#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(
		const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(0, 0),
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr);

	virtual void draw() const override;
	virtual char identify() const override;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	virtual void reset(const sf::Vector2f&) override;
	void dig();

private:
	int m_digState;
	virtual void setState(const int);
};
