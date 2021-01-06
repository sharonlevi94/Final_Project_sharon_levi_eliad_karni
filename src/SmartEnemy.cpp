//============================= include section ==============================
#include "SmartEnemy.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================

//============================== gets section ================================
//============================ methods section ===============================
void SmartEnemy::draw(sf::RenderWindow& window) const {
	window.draw(this->getSprite());
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================