//============================= include section ==============================
#include "BadGift.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
BadGift::BadGift(const sf::Vector2f location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
void BadGift::handleColision(vector<std::unique_ptr<RandEnemy>>& giftEnenmy,
	sf::Vector2f doorLoc, GameState& gameState) {
	giftEnenmy.push_back(std::make_unique<RandEnemy>(doorLoc, this->getSize()));
}
//============================================================================