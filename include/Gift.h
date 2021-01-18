#pragma once
#include "CollectableObject.h"
#include <vector>
#include "RandEnemy.h"
#include "GameState.h"
using std::vector;
class GameState;
class Gift :public CollectableObject
{
public:
public:
	Gift(const sf::Vector2f = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	

	virtual void reset()override;
	virtual void collect()override;
	virtual void playTurn(const sf::Time&, Board&)override;
	virtual void handleColision(vector<std::unique_ptr<RandEnemy>>&,
		sf::Vector2f,GameState&)=0;
private:

};