#pragma once
#include "StaticObjects.h"
class Gift :public StaticObjects
{
public:
	Gift();

	virtual void draw()const;
	virtual void playTurn();
	virtual void reset();
	bool is_collected()const;
	virtual char identify()const;
	void collect();

private:
	int m_state;
	const vector<sf::Sprite*> m_sprites;
	const sf::Vector2f m_initLoc;
};

Gift::Gift()
{
}

Gift::~Gift()
{
}