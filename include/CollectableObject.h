#pragma once

#include "StaticObject.h"

class CollectableObject : public StaticObject
{
public:
	CollectableObject();

	virtual void draw()const;
	virtual void playTurn();
	virtual void reset();
	bool is_collected()const;
	virtual char identify()const;
	virtual void collect();

private:
	
};