#pragma once
#include "StaticObject.h"

class Rod : public StaticObject
{
public:
	Rod(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

	virtual void playTurn(sf::Time) override;
	virtual void handleColision(GameObject&)override;
	virtual void handleColision(Wall&)override;
	virtual void handleColision(Player&)override;
private:
	//virtual void setState(const int);
	//virtual void setSprite(const sf::Sprite&);
};
