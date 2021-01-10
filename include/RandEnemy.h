#pragma once
#include "Enemy.h"
class RandEnemy: public Enemy
{
public:
	RandEnemy(const sf::Vector2f = sf::Vector2f(0, 0),
		const EffectsHolder & = EffectsHolder(),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	//virtual void draw(sf::RenderWindow&, const sf::Texture&) const;
	//virtual char identify() const override;
	virtual void playTurn(sf::Time) override;
	//virtual void reset(const sf::Vector2f&);

private:

	//virtual void setState(const int);
	//virtual void setLocation(const sf::Vector2f&);
};