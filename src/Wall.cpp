//============================= include section ==============================
#include "Wall.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Wall::Wall(const sf::Vector2f location,
		const EffectsHolder& effects,
		const sf::Vector2f& size )
	: StaticObject(location,effects,size,WALL_T), m_digState(STAND)
{}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Wall::dig(){}
//============================================================================
void Wall::handleColision(GameObject& obj) {
	obj.handleColision(*this);
}
//============================================================================
void Wall::playTurn(sf::Time) {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================