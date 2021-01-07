#ifndef _WALL_H_
#define _WALL_H_
#pragma once
#include "StaticObject.h"
#include "EffectsHolder.h"

class Wall : public StaticObject
{
public:
	Wall(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));

	void playTurn() override;
	void dig();

private:
	int m_digState;

};
#endif //_WALL_H_