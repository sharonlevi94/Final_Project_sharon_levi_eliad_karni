#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class MovingObject;

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;

	virtual void handleCollision(MovingObject&, const sf::Vector2f&) = 0;
private:
};
