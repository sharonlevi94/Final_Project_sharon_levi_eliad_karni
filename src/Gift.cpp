//============================= include section ==============================
#include "Gift.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Gift::Gift(const sf::Vector2f location,
	const sf::Vector2f& size)
	:CollectableObject(location, size, GIFT_T) {
	srand(17);
	this->m_type = rand() % NUM_OF_GIFT_TYPES;
}
//============================================================================
Gift::~Gift() { }

//============================================================================
void Gift::reset() {
	CollectableObject::reset();
}
//============================================================================
void Gift::collect() {
	CollectableObject::collect();
}
//============================================================================
void Gift::playTurn(const sf::Time& deltatime, const Board& board) {}
//============================== gets section ================================
int Gift::getType()const {
	return this->m_type;
}
//============================ methods section ===============================
//============================================================================
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================