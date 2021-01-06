#pragma once
#include "MovingObject.h"
#include "Wall.h"

class Player : public MovingObject
{
public:
	Player(const sf::Vector2f& location = sf::Vector2f(0, 0),
		const EffectsHolder& effects = EffectsHolder());

	virtual void draw(sf::RenderWindow& window) const;
	virtual void playTurn() override;
	//virtual void reset(const sf::Vector2f&) override;
	//virtual void addSprite(const sf::Sprite&)override;

	//virtual void fall(int) override;
	//virtual bool isMovePossible()const  override;

	//void dig(Wall&);

private:
	//virtual void setState(const int) override;
	virtual void setLocation(const sf::Vector2f&) override;
	//virtual void setSprite(const sf::Sprite&) override;
};