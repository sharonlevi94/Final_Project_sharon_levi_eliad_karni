//============================= include section ==============================
#include "Rod.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Rod::Rod(const sf::Vector2f location,
		const EffectsHolder& effects,
		const sf::Vector2f& size )
	: StaticObject(location, effects,size, ROD_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void Rod::playTurn(sf::Time){}
/*void Rod::draw(sf::RenderWindow& window)const {
	this->GameObject::draw(window);
}*/
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================