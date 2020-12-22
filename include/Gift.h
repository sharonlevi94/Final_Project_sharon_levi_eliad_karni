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
	int m_state;
	const vector<sf::Sprite*> m_sprites;
	const sf::Vector2f m_Loc;
	const sf::Vector2f m_size;
};