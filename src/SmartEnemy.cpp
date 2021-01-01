//============================= include section ==============================
#include "SmartEnemy.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
SmartEnemy::SmartEnemy(const sf::Vector2f location,
	const sf::Vector2f size,
	int state,
	const sf::Sprite& (*)(char),
	char type)
	: Enemy(location, size, state, nullptr, type) {}
//============================== gets section ================================
//============================ methods section ===============================

//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================