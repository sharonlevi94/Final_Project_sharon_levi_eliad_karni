//============================= include section ==============================
#include "CollectableObject.h"
#include "EffectsHolder.h"
#include "SFML/Graphics.hpp"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
CollectableObject::CollectableObject(const sf::Vector2f& location,
	const EffectsHolder & effects,
	const sf::Vector2f & size,
	char objectType)
	: StaticObject(location, effects, size, objectType),
	m_is_collected(false){}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
bool CollectableObject::is_collected()const { return (this->m_is_collected); }
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================
