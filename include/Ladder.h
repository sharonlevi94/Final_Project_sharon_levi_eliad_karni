#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
class Ladder: public StaticObject
{
public:
	Ladder(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

	virtual void playTurn(const sf::Time&,const Board&) override;
	virtual void handleColision(GameObject&)override;
	virtual void handleColision(Player&)override;
	virtual void handleColision(Enemy&)override;
private:

};