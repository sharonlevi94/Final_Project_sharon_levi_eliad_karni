#ifndef _MOVINGOBJECT_H_
#define _MOVINGOBJECT_H_
#pragma once
#include "GameObject.h"
class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;

	virtual void setLocation(const sf::Vector2f& movment);
private:
	
}; 
#endif //_BOARD_H_