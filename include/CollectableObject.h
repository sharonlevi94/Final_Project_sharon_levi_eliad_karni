#pragma once

#include "StaticObject.h"

class CollectableObject : public StaticObject
{
public:
	CollectableObject(const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(OBJ_WIDTH, OBJ_HEIGHT),
		int state = STAND,
		const sf::Sprite& (*)(char) = nullptr,
		char type = '\0');

	virtual bool is_collected()const =0;

private:
	bool m_is_collected;

	virtual void collect()=0;
};