#pragma once
#include "GameObject.h"
class MovingObject : public GameObject
{
public:
	//using GameObject::GameObject;
	MovingObject(const sf::Vector2f location = sf::Vector2f(0, 0),
				const sf::Vector2f size = sf::Vector2f(OBJ_WIDTH, OBJ_HEIGHT),
				int state = STAND,
				const sf::Sprite& (*)(char) = nullptr,
				char type = '\0');
	virtual void fall(int)=0;
	virtual bool isMovePossible()const=0;

private:
	virtual void setLocation (const sf::Vector2f&)=0;
};