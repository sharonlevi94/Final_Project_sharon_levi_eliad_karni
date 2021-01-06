//============================= include section ==============================
#include "Ladder.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Ladder::Ladder(const sf::Vector2f& location ,
	const EffectsHolder& effects)
	: StaticObject(location,effects,LADDER_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void Ladder::playTurn() {}
void Ladder::draw(sf::RenderWindow& window)const{
	this->GameObject::draw(window);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================