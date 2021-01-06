//============================= include section ==============================
#include "Wall.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Wall::Wall(const sf::Vector2f& location,
	const EffectsHolder& effects)
	:StaticObject(location,effects,WALL_T), m_digState(STAND)
{}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Wall::dig(){}
//============================================================================
void Wall::draw(sf::RenderWindow& window)const {
	this->GameObject::draw(window);
}
//============================================================================
void Wall::playTurn() {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================