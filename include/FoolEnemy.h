//============================ include section ===============================
#pragma once
#include "Enemy.h"
/*============================================================================
* Class: Fool Enemy.
* This class represent the fool enemy obhect in the game.
* this class is derives from the class enemy.
 ============================================================================*/
class FoolEnemy: public Enemy
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	FoolEnemy(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0));
	//=========================== methods section ============================
	virtual void playTurn(const sf::Time&, Board&)override;
	virtual void handleCollision(Wall&, const sf::Vector2f&)override;
	//========================= private section ==============================
private:
<<<<<<< HEAD
=======
	bool m_turn;
>>>>>>> 39bc6ed7fc5c0d63092256c2093a1d97a3755878
};