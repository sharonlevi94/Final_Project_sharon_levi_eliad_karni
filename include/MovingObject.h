#pragma once
#include "GameObject.h"
class MovingObject : public GameObject
{
public:
<<<<<<< HEAD
	MovingObject();
	
=======
	MovingObject(
		const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(0, 0),
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr);
>>>>>>> df119aebcdfdccd602898c8cf82565d0722f11d4
	virtual void fall();

private:
	
};