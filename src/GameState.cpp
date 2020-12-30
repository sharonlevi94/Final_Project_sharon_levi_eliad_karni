//============================= include section ==============================
#include "GameState.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameState::GameState(const sf::Vector2f& location, const sf::Vector2f& size,
	int levelTime, sf::Font* fontPtr) :
	m_clock(sf::Clock()), m_level(1), m_lifes(NUM_OF_LIFE), 
	m_location(location), m_score(0), m_size(size), m_levelTime(levelTime),
	m_fontPtr(fontPtr){}
//============================ methods section ===============================
//============================================================================
void GameState::draw (void (*drawFunc)(const sf::Drawable&, const sf::RenderStates&)) {
	sf::Text text;
	text.setFont(*this->m_fontPtr);
	text.setString("level: " + this->m_level);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(20);
	text.setPosition(this->m_location);
	sf::RectangleShape sss(this->m_size);
	sss.setPosition(this->m_location);
	sss.setFillColor(sf::Color::Black);

	drawFunc(text, sf::RenderStates::Default);
	drawFunc(sss, sf::RenderStates::Default);

}
//============================================================================
void GameState::levelup() { ++this->m_level; }
//============================================================================
void GameState::collectedCoin() {

}
//============================================================================
void GameState::died() {
	--this->m_lifes;
	this->m_clock.restart();
}