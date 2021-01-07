//============================= include section ==============================
#include "RandEnemy.h"
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
RandEnemy::RandEnemy(const sf::Vector2f location,
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
void RandEnemy::playTurn(const Board& board) {}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================