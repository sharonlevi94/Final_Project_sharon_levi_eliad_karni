//============================= include section ==============================
#include "GameState.h"
#include "EffectsHolder.h"
#include <string>
#include "Macros.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameState::GameState(const EffectsHolder& effects,
	const sf::Vector2f& location,
	const sf::Vector2f& size):
	m_size(size), m_location(location), m_clock(sf::Clock()),
	m_stateText(sf::Text()), m_levelTime(sf::Time()), m_level(0), m_score(0),
	m_lifes(3), m_turnTime(sf::Time()){
	this->m_stateText.setFont(effects.getFont(ARIEL_FONT));
	this->m_stateText.setFillColor(sf::Color::White);
}
//============================ methods section ===============================
//============================================================================
void GameState::draw (sf::RenderWindow& window){
	this->m_stateText.setPosition(this->m_location);

	this->m_stateText.setString("level: " + std::to_string(this->m_level)
		+  " lifes: " + std::to_string(this->m_lifes) + " time left: " + 
		std::to_string((this->m_levelTime.asSeconds() - 
			(this->m_clock.getElapsedTime().asSeconds()))));
	std::cout << (std::string)this->m_stateText.getString() << std::endl;
	this->m_stateText.scale(sf::Vector2f(
	this->m_size.x / this->m_stateText.getLocalBounds().width,
	this->m_size.y / this->m_stateText.getLocalBounds().height
	));

	window.draw(this->m_stateText);
}
//============================================================================
bool GameState::isTimeUp() {
	if (this->m_levelTime.asSeconds() == -1)
		return false;
	return(this->m_clock.getElapsedTime().asSeconds() == 
		this->m_levelTime.asSeconds());
}
//============================================================================
void GameState::levelup(int time) { 
	this->m_score += this->m_level * 50;
	++this->m_level;
	this->m_turnTime = sf::seconds((float)time);
}
//============================================================================
void GameState::collectedCoin() { this->m_score += this->m_level * 2; }
//============================================================================
void GameState::died() {
	--this->m_lifes;
	this->m_clock.restart();
}
//============================================================================
bool GameState::nextTurn() {
	if (this->m_clock.getElapsedTime().asSeconds() > this->m_turnTime.asSeconds()) {
		this->m_turnTime += sf::seconds((float)0.01);
		return true;
	}
	return false;
		
}