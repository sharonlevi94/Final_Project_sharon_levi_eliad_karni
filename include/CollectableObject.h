#pragma once

#include "StaticObject.h"

class CollectableObject : public StaticObject
{
public:
	CollectableObject(const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(0, 0),
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr);

	bool is_collected()const;

private:
	bool m_is_collected;

	virtual void collect();
};