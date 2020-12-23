#pragma once
#include "CollectableObject.h"
class Gift :public CollectableObject
{
public:
	Gift();

	virtual void draw()const;
	virtual void playTurn();
	virtual void reset();
	bool is_collected()const;
	virtual char identify()const;
	virtual void collect();

private:
	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
	virtual void setSprite(const sf::Sprite&);
};