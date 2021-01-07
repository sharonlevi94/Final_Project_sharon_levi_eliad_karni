//============================= include section ==============================
#include "Gift.h"
#include "Utilities.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Gift::Gift(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	:CollectableObject(location, effects, size, COIN_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Gift::playTurn() {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================