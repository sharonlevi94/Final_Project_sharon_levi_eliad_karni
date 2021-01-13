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
void Coin::playTurn(const sf::Time&, const Board&) {}
void Coin::handleColision(Player&) {}
void Coin::handleColision(Enemy&) {}
void Coin::handleColision(GameObject& obj) {
	obj.handleColision(*this);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================