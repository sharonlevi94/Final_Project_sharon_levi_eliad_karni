#ifndef _ENEMY_H
#define _ENEMY_H
#pragma once
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
class Enemy: public MovingObject
{
public:
	using MovingObject::MovingObject;

	bool isCatchedPlayer(const sf::Vector2f&);
private:
	 
};
#endif //_BOARD_H_