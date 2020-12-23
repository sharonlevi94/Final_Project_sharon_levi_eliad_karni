#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class StaticObject : public GameObject
{
public:
	StaticObject(const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(0, 0),
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr);

private:
};
