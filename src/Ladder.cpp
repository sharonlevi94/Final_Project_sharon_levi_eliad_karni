//============================= include section ==============================
#include "Ladder.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Ladder::Ladder(const sf::Vector2f location,
		const EffectsHolder& effects,
		const sf::Vector2f& size)
	: StaticObject(location,effects,size,LADDER_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void Ladder::playTurn() {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================