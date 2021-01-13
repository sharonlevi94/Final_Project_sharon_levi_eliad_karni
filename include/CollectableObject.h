#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class CollectableObject : public StaticObject{
public:
	CollectableObject(const sf::Vector2f& = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0),
		char objectType = NOTHING);

	virtual bool is_collected()const;
	virtual void draw(sf::RenderWindow&)override;
	virtual void reset()override;
	virtual void collect();

private:
	bool m_is_collected;

	
};