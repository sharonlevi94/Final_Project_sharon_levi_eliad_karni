#ifndef _SMARTENEMY_H
#define _SMARTENEMY_H
#pragma once
#include "Enemy.h"
class SmartEnemy: public Enemy
{
public:
	SmartEnemy(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));
	
	virtual void playTurn() override;
private:
}; 
#endif //_BOARD_H_