//============================= include section ==============================
#include "FoolEnemy.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
FoolEnemy::FoolEnemy(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	:Enemy(location, effects, size, ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
/*void SmartEnemy::draw(sf::RenderWindow& window) const {
	window.draw(this->getSprite());
}*/
//============================================================================
void FoolEnemy::playTurn(const Board& board) {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================