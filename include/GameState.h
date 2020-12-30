#pragma once
//============================= include section ==============================
#include <SFML/graphics.hpp>
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

	GameState          (const sf::Vector2f& location = sf::Vector2f(0,0),
		const sf::Vector2f& size = sf::Vector2f(0,0), int levelTime = 0,
		sf::Font* = nullptr);
	//=========================== method section =============================

	void draw(void(*)(const sf::Drawable&));
	void levelup       ();
	void collectedCoin ();
	void died          ();

private:
	//======================== members section ===============================
	sf::Vector2f     m_size;
	sf::Vector2f m_location;
	sf::Clock       m_clock;
	sf::Font*     m_fontPtr;
	int         m_levelTime;
	int             m_level;
	int             m_score;
	int             m_lifes;
};