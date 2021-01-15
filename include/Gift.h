#pragma once
#include "CollectableObject.h"
#include <vector>
#include "FoolEnemy.h"
#include "GameState.h"
using std::vector;
class GameState;
class Gift :public CollectableObject
{
public:
public:
	Gift(const sf::Vector2f = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	~Gift();
	
	int getType()const;

	virtual void reset()override;
	virtual void collect()override;
	virtual void playTurn(const sf::Time&, const Board&)override;
	void handleColision(vector<std::unique_ptr<FoolEnemy>>&,sf::Vector2f,GameState&);
private:
	int m_type;
};