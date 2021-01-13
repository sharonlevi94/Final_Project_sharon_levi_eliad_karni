//============================= include section ==============================
#include "Coin.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Coin::Coin(const sf::Vector2f location,
		const sf::Vector2f& size)
	:CollectableObject(location, size, COIN_T) {
	++m_coinsCounter;
}
//============================================================================
Coin::~Coin() { --m_coinsCounter; }
//========================== statics declaretions ============================
unsigned int Coin::m_coinsCounter = 0;
//============================================================================
unsigned int Coin::getCoinsCounter() { return m_coinsCounter; }
//============================================================================
void Coin::reset() {
	CollectableObject::reset();
	++m_coinsCounter;
}
//============================================================================
void Coin::collect() {
	CollectableObject::collect();
	--m_coinsCounter;
}

void Coin::playTurn(const sf::Time& deltatime, const Board& board) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================