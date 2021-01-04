#pragma once
#include "GameObject.h"
class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;

	virtual void fall(int)=0;
	virtual bool isMovePossible()const=0;

private:
	virtual void setLocation (const sf::Vector2f&)=0;
};