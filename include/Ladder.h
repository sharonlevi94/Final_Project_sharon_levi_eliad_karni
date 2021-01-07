#ifndef _LADDER_H
#define _LADDER_H
#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
class Ladder: public StaticObject
{
public:
	Ladder(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

	virtual void playTurn() override;

private:
};
#endif //_BOARD_H_