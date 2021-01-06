//============================= include section ==============================
#include "Coin.h"
#include "Utilities.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Coin::Coin(const sf::Vector2f& location,
	const EffectsHolder& effects)
	:CollectableObject(location,effects,COIN_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Coin::playTurn() {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================