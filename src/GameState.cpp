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
	int levelTime, const sf::Vector2f& size) :
	m_clock(sf::Clock()), 
	m_level(0),
	m_lifes(NUM_OF_LIFE), 
	m_location(location), 
	m_score(0), m_size(size), 
	m_levelTime(levelTime),
	m_stateText(sf::Text()),
	m_turnTime(0){
	this->m_stateText.setFont(effects.getFont(ARIEL_FONT));
}
//============================ methods section ===============================
//============================================================================
void GameState::draw (sf::RenderWindow& window){
	this->m_stateText.setFillColor(sf::Color::Black);
	this->m_stateText.setPosition(this->m_location);

	this->m_stateText.setString("level: " + std::to_string(this->m_level)
		+  " lifes: " + std::to_string(this->m_lifes) + " time left: " + 
		std::to_string(this->m_levelTime - this->m_clock.getElapsedTime()
			.asMilliseconds()));
	this->m_stateText.scale(sf::Vector2f(
	this->m_size.x / this->m_stateText.getLocalBounds().width,
	this->m_size.y / this->m_stateText.getLocalBounds().height
	));

	window.draw(this->m_stateText);
}
//============================================================================
void GameState::levelup(int time) { 
	this->m_score += this->m_level * 50;
	++this->m_level;
	this->m_turnTime = time;
}
//============================================================================
void GameState::collectedCoin() { this->m_score += this->m_level * 2; }
//============================================================================
void GameState::died() {
	--this->m_lifes;
	this->m_levelTime = 0;
	this->m_clock.restart();
}
//============================================================================
bool GameState::nextTurn() {
	if (this->m_clock.getElapsedTime().asMilliseconds() > this->m_turnTime) {
		++this->m_turnTime;
		return true;
	}
	return false;
		
}