#ifndef _PLAYER_H_
#define _PLAYER_H_
#pragma once
#include "MovingObject.h"
#include "Wall.h"

class Player : public MovingObject
{
public:
	Player(const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0));
	virtual void playTurn() override;
	//void dig(Wall&);

private:
};
#endif //_BOARD_H_