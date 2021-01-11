#pragma once
#include "Enemy.h"

class FoolEnemy: public Enemy
{
public:
	FoolEnemy(const sf::Vector2f = sf::Vector2f(0, 0),
		const EffectsHolder & = EffectsHolder(),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	
	//virtual void fall();
	//virtual void draw(sf::RenderWindow&, const sf::Texture&) const;
	virtual void playTurn(const sf::Time&, const Board&)override;
	virtual void handleColision(GameObject&)override;
	//virtual void reset(const sf::Vector2f&);

private:

	//virtual void setState(const int);
	//virtual void setLocation(const sf::Vector2f&);
};