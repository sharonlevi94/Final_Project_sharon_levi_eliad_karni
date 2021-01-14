#pragma once
#include "CollectableObject.h"
class Gift :public CollectableObject
{
public:
public:
	Gift(const sf::Vector2f = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	~Gift();
	
	static unsigned int getGiftsCounter();
	virtual void reset()override;
	virtual void collect()override;
	virtual void playTurn(const sf::Time&, const Board&)override;
private:
	static unsigned int m_giftsCounter;
};