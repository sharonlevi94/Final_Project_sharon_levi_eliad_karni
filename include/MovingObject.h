#pragma once
#include "GameObject.h"
class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;
	MovingObject(const sf::Vector2f = sf::Vector2f(0, 0),
		const EffectsHolder & = EffectsHolder(),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	virtual void setLocation(const sf::Vector2f&);
	virtual void setLastLocation();
	const sf::Vector2f& getLastLocation()const;
private:
	sf::Vector2f m_lastLocation;
};