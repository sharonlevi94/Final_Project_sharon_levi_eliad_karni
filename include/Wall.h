#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(const sf::Vector2f& location = sf::Vector2f(0, 0),
		const EffectsHolder& effects = EffectsHolder());

	virtual void draw(sf::RenderWindow&)const override;
	void playTurn() override;
	void dig();

private:
	int m_digState;

};
