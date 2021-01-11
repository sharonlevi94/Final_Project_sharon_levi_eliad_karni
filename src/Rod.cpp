//============================= include section ==============================
#include "Rod.h"
#include "Utilities.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Rod::Rod(const sf::Vector2f location,
		const EffectsHolder& effects,
		const sf::Vector2f& size )
	: StaticObject(location, effects,size, ROD_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void Rod::playTurn(const sf::Time& deltaTime,const Board& board){}
void Rod::handleColision(Wall&){}
void  Rod::handleColision(Enemy&) {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================