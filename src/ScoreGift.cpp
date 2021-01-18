//============================= include section ==============================
#include "ScoreGift.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
ScoreGift::ScoreGift(const sf::Vector2f location,
	const sf::Vector2f& size)
	:Gift(location, size) {
}
//============================ methods section ===============================
void ScoreGift::handleColision(vector<std::unique_ptr<RandEnemy>>& giftEnenmy,
	sf::Vector2f doorLoc, GameState& gameState) {
	gameState.addScore(BONUS);
}
//============================================================================