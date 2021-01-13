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

//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================