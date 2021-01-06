#pragma once
#include "Enemy.h"
class SmartEnemy: public Enemy
{
public:
	SmartEnemy(const sf::Vector2f& location = sf::Vector2f(0, 0),
		const EffectsHolder& effects = EffectsHolder());
	
	virtual void draw(sf::RenderWindow&) const;
	virtual void playTurn() override;

	//virtual bool isMovePossible()const  override;

private:

	//virtual void setState(const int) override;
//	virtual void setLocation(const sf::Vector2f&) override;
	//virtual void setSprite(const sf::Sprite&) override;
};