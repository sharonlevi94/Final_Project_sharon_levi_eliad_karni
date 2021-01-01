//============================= include section ==============================
#include "MovingObject.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
MovingObject::MovingObject(const sf::Vector2f location, 
						   const sf::Vector2f size,
						   int state,
						   const sf::Sprite& (*)(char),
					       char type )
	: GameObject(location,size,state,nullptr,type)
{}
//============================== gets section ================================
//============================ methods section ===============================

//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================