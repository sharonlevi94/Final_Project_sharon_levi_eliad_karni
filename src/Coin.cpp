//============================= include section ==============================
#include "Coin.h"
#include "Board.h"
#include "Utilities.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Coin::Coin(const sf::Vector2f location,
		const sf::Vector2f& size)
	:CollectableObject(location,size,COIN_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================