//============================= include section ==============================
#include "FoolEnemy.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
FoolEnemy::FoolEnemy(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	:Enemy(location, effects, size, ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void FoolEnemy::playTurn(sf::Time deltaTime) {
	const auto SpeedPerSecond = 200.f;
	 this->setLocation(sf::Vector2f(-1, 0) * SpeedPerSecond * deltaTime.asSeconds());
	 this->setLocation(sf::Vector2f(1, 0) * SpeedPerSecond * deltaTime.asSeconds());
	
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================