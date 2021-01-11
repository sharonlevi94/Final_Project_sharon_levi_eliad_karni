//============================= include section ==============================
#include "gift.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Gift::Gift(const sf::Vector2f& location,
	const EffectsHolder& effects)
	: CollectableObject(location,effects,GIFT_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void Gift::playTurn(const sf::Time& deltaTime, const Board& board) {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================