//============================= include section ==============================
#include "TimeGift.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
TimeGift::TimeGift(const sf::Vector2f location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
void TimeGift::handleColision(vector<std::unique_ptr<RandEnemy>>& giftEnenmy,
	sf::Vector2f doorLoc, GameState& gameState) {
	 gameState.addTimeBonus(sf::seconds(BONUS));
}
//============================================================================