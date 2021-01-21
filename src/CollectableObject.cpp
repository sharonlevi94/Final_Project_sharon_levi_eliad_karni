//============================= include section ==============================
#include "CollectableObject.h"
#include "SFML/Graphics.hpp"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
CollectableObject::CollectableObject(const sf::Vector2f& location,
	const sf::Vector2f & size,
	char objectType)
	: StaticObject(location, size, objectType),
	m_is_collected(false){}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
bool CollectableObject::is_collected()const { return (this->m_is_collected); }
//============================================================================
void CollectableObject::draw(sf::RenderWindow& window) {
	if (!this->m_is_collected)
		this->GameObject::draw(window);
}
//============================================================================
void CollectableObject::reset() {
	this->GameObject::reset();
	this->m_is_collected = false;
}
//============================================================================
void CollectableObject::collect() { this->m_is_collected = true; }
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================
