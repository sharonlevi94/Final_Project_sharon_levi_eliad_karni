//============================= include section ==============================
#include "Door.h"
#include "Utilities.h"
#include "Board.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Door::Door(const sf::Vector2f location,
	const sf::Vector2f& size)
	: StaticObject(location, size, DOOR_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void Door::playTurn(const sf::Time& deltaTime, Board& board) {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================