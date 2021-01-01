//============================= include section ==============================
#include "Enemy.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Enemy::Enemy(const sf::Vector2f location,
	const sf::Vector2f size,
	int state,
	const sf::Sprite& (*)(char),
	char type)
	: MovingObject(location,size,state,nullptr,type) {}
//============================== gets section ================================
//============================ methods section ===============================

//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================