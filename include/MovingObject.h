#pragma once
#include "GameObject.h"
class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;

	virtual void setLocation(const sf::Vector2f& movment,
		const sf::Vector2f& areaSize);
	bool moveIsPossible(const sf::Vector2f&,
		const sf::Vector2f& ) const;
private:
	
};