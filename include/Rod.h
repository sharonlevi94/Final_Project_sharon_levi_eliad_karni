#ifndef _ROD_H
#define _ROD_H
#pragma once
#include "StaticObject.h"
class Rod : public StaticObject
{
public:
	Rod(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

	virtual void playTurn() override;

private:
};
#endif //_ROD_H_