//============================= include section ==============================
#include "RandEnemy.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
RandEnemy::RandEnemy(const sf::Vector2f location,
	const EffectsHolder& effects,
	const sf::Vector2f& size)
	:Enemy(location, effects, size, ENEMY_T) {}
//============================== gets section ================================
//============================ methods section ===============================
void RandEnemy::playTurn(sf::Time deltaTime){
	srand(time(NULL));
	const auto SpeedPerSecond = 200.f;
	int rand_move =rand()%4;
	switch (rand_move)
	{
	case 0: this->setLocation(sf::Vector2f(0, -1) * SpeedPerSecond * deltaTime.asSeconds());
		break;
	case 1: this->setLocation(sf::Vector2f(-1, 0) * SpeedPerSecond * deltaTime.asSeconds());
		break;
	case 2: this->setLocation(sf::Vector2f(1, 0) * SpeedPerSecond * deltaTime.asSeconds());
		break;
	default:
		this->setLocation(sf::Vector2f(0, 1) * SpeedPerSecond * deltaTime.asSeconds());
		break;
	}
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================