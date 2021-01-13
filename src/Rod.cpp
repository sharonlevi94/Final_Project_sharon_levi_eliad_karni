//============================= include section ==============================
#include "Rod.h"
#include "Utilities.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Rod::Rod(const sf::Vector2f location,
		const sf::Vector2f& size )
	: StaticObject(location, size, ROD_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void Rod::playTurn(const sf::Time& deltaTime,const Board& board){}
void Rod::handleColision(Player&) {/*ignore*/ }
void  Rod::handleColision(Enemy&) {}
void Rod::handleColision(GameObject& obj) {
	obj.handleColision(*this);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================