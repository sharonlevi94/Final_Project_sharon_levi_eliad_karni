#pragma once
#include "StaticObject.h"
class Wall : public StaticObject
{
public:
	Wall(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));
	void playTurn(const sf::Time&,const Board&) override;
	void dig();
	virtual void handleColision( Wall&)override;
	virtual void handleColision(Enemy&)override;
private:
	int m_digState;
};
