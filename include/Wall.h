#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

//	virtual void draw(sf::RenderWindow&)const override;
	void playTurn(sf::Time) override;
	void dig();

private:
	int m_digState;

};
