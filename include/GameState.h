#pragma once
//============================= include section ==============================
#include <SFML/graphics.hpp>
#include "EffectsHolder.h"
#include <iostream>
/*============================================================================
* GameState
* the class handle the game's status parameters and print its stats by
* the demanded syntax.
*/
class GameState
{
public:
	//============== constructors and destructors section ====================

	GameState(const EffectsHolder& effects = EffectsHolder(),
		const sf::Vector2f& location = sf::Vector2f(0,0),
		const sf::Vector2f& size = sf::Vector2f(0, 0));
	//=========================== method section =============================

	void draw(sf::RenderWindow& window);
	void levelup       (int);
	void collectedCoin ();
	void died          ();
	bool nextTurn	   ();
	bool isTimeUp();

private:
	//======================== members section ===============================
	sf::Vector2f     m_size;
	sf::Vector2f m_location;
	sf::Clock       m_clock;
	//recommanded to save Text as parameter thoe its heavy creating.
	sf::Text	m_stateText;
	sf::Time         m_levelTime;
	int             m_level;
	int             m_score;
	int             m_lifes;
	sf::Time		 m_turnTime;
};