#pragma once
#include "MovingObject.h"
#include <SFML/Graphics.hpp>
class Enemy: public MovingObject
{
public:
	Enemy();

	bool isCatchedPlayer(const sf::Vector2f&);
private:
	 
};