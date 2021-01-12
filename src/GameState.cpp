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
	m_clock(), m_stateText(), m_levelTime(), m_level(0), m_score(0),
	m_lifes(NUM_OF_LIFE), m_background(size){
	this->m_background.setPosition(location);
	this->m_background.setTexture(&effects.getTexture(GAME_STATE));

	this->m_stateText.setFont(effects.getFont(ARIEL_FONT));
	this->m_stateText.setFillColor(sf::Color::White);
}
//============================ methods section ===============================
//============================================================================
void GameState::draw (sf::RenderWindow& window){
	window.draw(this->m_background);

	this->m_stateText.setPosition(this->getLocation());
	this->m_stateText.setString(" level: " + std::to_string(this->m_level)
		+  " | lifes: " + std::to_string(this->m_lifes) + " | time left: " + 
		std::to_string(-1) + " | Score: " + std::to_string(this->m_score) + " ");
	//std::cout << (std::string)this->m_stateText.getString() << std::endl;
	this->m_stateText.setScale(sf::Vector2f(
	this->getSize().x / this->m_stateText.getLocalBounds().width,
	this->getSize().y / this->m_stateText.getLocalBounds().height
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
}
//============================================================================
void GameState::collectedCoin() { this->m_score += this->m_level * 2; }
//============================================================================
void GameState::died() {
	--this->m_lifes;
	this->m_clock.restart();
}
//============================================================================
bool GameState::isGameOver(){
	if (this->m_lifes <= 0)
		return true;
	return false;
}
//============================================================================
sf::Vector2f GameState::getSize()const { 
	return this->m_background.getSize(); 
}
//============================================================================
sf::Vector2f GameState::getLocation()const {
	return this->m_background.getPosition();
}
