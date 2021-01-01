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
void GameState::draw //(sf::RenderWindow& window){
  (void (*drawFunc)(const sf::Drawable&, const sf::RenderStates&)) {
		sf::Font font;
	font.loadFromFile("ARIALBD.TTF");
	sf::Text text;
	text.setFont(font);
	//text.setFont(*this->m_fontPtr);
	text.setString("level: ");
	text.setFillColor(sf::Color::White);
	text.setPosition(this->m_location);
	sf::RectangleShape sss(sf::Vector2f(300,300));
	sss.setPosition(this->m_location);
	sss.setFillColor(sf::Color::Green);

	drawFunc(sss, sf::RenderStates());
	//window.draw(sss);
	//window.draw(text);
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

void GameState::test(void (GameState::*died)()) {
	std::cout << "yey!!!!";
}