#pragma once
#include "StaticObject.h"

class Rod : public StaticObject
{
public:
	Rod();
	virtual void draw() const override;
	virtual char identify() const override;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	virtual void reset(const sf::Vector2f&) override;
	virtual int getState()const ;

private:
	virtual void setState(const int);
};
