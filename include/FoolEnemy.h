#ifndef _FOOLENEMY_H_
#define _FOOLENEMY_H_
#pragma once
#include "Enemy.h"
#include "EffectsHolder.h"

class FoolEnemy : public Enemy
{
public:
	FoolEnemy(const sf::Vector2f = sf::Vector2f(0, 0),
		const EffectsHolder & = EffectsHolder(),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	virtual void playTurn() override;
private:
}; 
#endif //_FOOLENEMY_H_