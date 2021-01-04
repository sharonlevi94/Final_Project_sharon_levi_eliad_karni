#ifndef _COLLECTABLEOBJECT_
#define _COLLECTABLEOBJECT_
#pragma once
#include "StaticObject.h"

class CollectableObject : public StaticObject
{
public:
	using StaticObject::StaticObject;

	//virtual bool is_collected()const =0;

private:
	bool m_is_collected;

//	virtual void collect()=0;
};
#endif // !_COLLECTABLEOBJECT_