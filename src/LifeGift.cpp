//============================= include section ==============================
#include "LifeGift.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
LifeGift::LifeGift(const sf::Vector2f location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
void LifeGift::handleColision(vector<std::unique_ptr<RandEnemy>>& giftEnenmy,
	sf::Vector2f doorLoc, GameState& gameState) {
	gameState.addLife();
}
//============================================================================