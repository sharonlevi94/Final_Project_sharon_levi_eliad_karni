#pragma once
#include "Enemy.h"

class FoolEnemy: public Enemy
{
public:
	FoolEnemy(const sf::Vector2f& location = sf::Vector2f(0, 0),
		const EffectsHolder& effects = EffectsHolder());
	
	virtual void fall();
	virtual void draw(sf::RenderWindow&, const sf::Texture&) const;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);

private:

	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
};