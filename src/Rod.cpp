//============================= include section ==============================
#include "Rod.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Rod::Rod(const sf::Vector2f& location = sf::Vector2f(0, 0),
	const EffectsHolder& effects = EffectsHolder())
	: StaticObject(location, effects, ROD_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================