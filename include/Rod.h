#pragma once
#include "StaticObject.h"

class Rod : public StaticObject
{
public:
	Rod(const sf::Vector2f& location = sf::Vector2f(0, 0),
		const EffectsHolder& effects = EffectsHolder());

	virtual void draw(sf::RenderWindow&)const override;
//	virtual char identify() const override;
	virtual void playTurn() override;
	//virtual void reset(const sf::Vector2f& )override;
	//virtual void addSprite(const sf::Sprite&)override;

private:
	//virtual void setState(const int);
	//virtual void setSprite(const sf::Sprite&);
};
