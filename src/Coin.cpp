//============================= include section ==============================
#include "Coin.h"
#include "Board.h"
#include "Utilities.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Coin::Coin(const sf::Vector2f location,
		const EffectsHolder& effects,
		const sf::Vector2f& size)
	:CollectableObject(location,effects,size,COIN_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Coin::playTurn(const sf::Time&, const Board&) {}
void Coin::handleColision(Wall&) {}
void Coin::handleColision(Enemy&) {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================