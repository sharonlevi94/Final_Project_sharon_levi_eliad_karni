#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	//virtual void handleColision(Player&) = 0;
	//virtual void handleColision(Enemy&) = 0;
private:
};
