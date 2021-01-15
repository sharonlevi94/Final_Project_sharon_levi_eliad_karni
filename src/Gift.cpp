//============================= include section ==============================
#include "Gift.h"
#include "Macros.h"

//============================= public section ===============================
//==================== Constructors & distructors section ====================
Gift::Gift(const sf::Vector2f location,
	const sf::Vector2f& size)
	:CollectableObject(location, size, GIFT_T) {
	//srand(17);
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
void Gift::handleColision(vector<std::unique_ptr<FoolEnemy>>& giftEnenmy,
	sf::Vector2f doorLoc, GameState& gameState) {
	//sf::Time timeBonus = sf::seconds(20);
	switch (this->m_type)
	{
	case TIME_BONUS: gameState.addTimeBonus(sf::seconds(BONUS)); 
		break;
	case ADD_LIFE: gameState.addLife(); 
		break;
	case ADD_SCORE: gameState.addScore(BONUS);
		break;
	case ADD_ENEMY: giftEnenmy.push_back(std::make_unique<FoolEnemy>(doorLoc,this->getSize()));
		break;
	default:
		break;
	}
}
//============================================================================
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================