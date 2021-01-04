//============================= include section ==============================
#include "Player.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Player::Player(const sf::Vector2f location ,
	const sf::Vector2f size ,
	int state,
	const sf::Sprite& (*)(char) ,
	char type )
	: MovingObject(location, size, state, nullptr, type)
{}
//============================== gets section ================================

//============================ methods section ===============================
//============================ private section ===============================
//============================== sets section ================================
//============================ methods section ===============================