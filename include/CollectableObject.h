#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "EffectsHolder.h"

class CollectableObject : public StaticObject{
public:
	CollectableObject(const sf::Vector2f& = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0),
		char objectType = NOTHING);

	virtual bool is_collected()const;

private:
	bool m_is_collected;
};