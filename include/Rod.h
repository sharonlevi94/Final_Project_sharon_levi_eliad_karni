#pragma once
#include "StaticObject.h"

class Rod : public StaticObject
{
public:
	Rod(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

	virtual void playTurn(const sf::Time&,const Board&) override;
	virtual void handleColision(Wall&)override;
	virtual void handleColision(Enemy&)override;

private:
};
