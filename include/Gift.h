#pragma once
#include "CollectableObject.h"
#include <vector>
#include "RandEnemy.h"
#include "GameState.h"


using std::vector;

class Controller;

class Gift :public CollectableObject
{
public:
public:
	Gift(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	

	virtual void reset()override;
	virtual void collect()override;
	virtual void handleColision(Controller&)=0;
private:

};