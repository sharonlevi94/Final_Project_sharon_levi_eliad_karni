#pragma once
#include "GameObject.h"
class MovingObject : public GameObject
{
public:

	MovingObject();
	

	MovingObject(
		const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(0, 0),
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr);
<<<<<<< HEAD

	virtual void fall();

=======
	void fall(int);
	bool isMovePossible()const;
>>>>>>> 60c0021056213ed6e3bde838693cdf5a7bfd51e3
private:
	
};