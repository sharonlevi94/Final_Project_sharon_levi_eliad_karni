//============================= include section ==============================
#include "Wall.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Wall::Wall(const sf::Vector2f& location = sf::Vector2f(0, 0),
	const EffectsHolder& effects = EffectsHolder())
	:StaticObject(location,effects,WALL_T)
{}
//============================== gets section ================================
//============================ methods section ===============================
//----------------------------------------------------------------------------
void Wall::dig(){}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================