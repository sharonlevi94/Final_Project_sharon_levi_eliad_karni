//============================= include section ==============================
#include "Ladder.h"
#include "Utilities.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Ladder::Ladder(const sf::Vector2f location,
		const EffectsHolder& effects,
		const sf::Vector2f& size)
	: StaticObject(location,effects,size,LADDER_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void Ladder::playTurn(const sf::Time& deltaTime,const Board& board) {}
void Ladder::handleColision(Player&) {/*ignore*/ }
void Ladder::handleColision(Enemy&) {}
void Ladder::handleColision(GameObject& obj) {
	obj.handleColision(*this);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================