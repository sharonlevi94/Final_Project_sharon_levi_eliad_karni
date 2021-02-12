//============================= include section ==============================
#include "GameState.h"
#include "Resources.h"
#include <string>
#include "Macros.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameState::GameState(const sf::Vector2f& location,
	const sf::Vector2f& size):
	m_clock(), m_stateText(), m_levelTime(), m_level(0), m_score(0),
	m_lifes(NUM_OF_LIFE), m_background(size){
	this->m_background.setPosition(location);
	this->m_background.setTexture(&Resources::instance().getTexture(GAME_STATE));

	this->m_stateText.setFont(Resources::instance().getFont(ARIEL_FONT));
	this->m_stateText.setFillColor(sf::Color::White);
}
//============================ methods section ===============================
//============================================================================
void GameState::draw (sf::RenderWindow& window){

	window.draw(this->m_background);       
	this->m_stateText.setPosition(this->getLocation());
	//clac output:
	std::string time = this->getRemindMin();
	if (time != "-1") {
		time += ":";
		time += this->getRemindSec();
	}
	else
		time = "inf";
	           
	this->m_stateText.setString(
		" level: " + std::to_string(this->m_level) +
		" | lives: " + std::to_string(this->m_lifes) +
		" | time left: " + time +
		" | Score: " + std::to_string(this->m_score) + " ");
	this->m_stateText.setScale(sf::Vector2f(
	this->getSize().x / this->m_stateText.getLocalBounds().width,
	this->getSize().y / this->m_stateText.getLocalBounds().height
	));

	window.draw(this->m_stateText);
}
//============================================================================
/*This method check if the time of the current level is over.*/
bool GameState::isTimeUp() {
	if (this->m_levelTime.asSeconds() == -1)
		return false;
	return (this->m_clock.getElapsedTime() > this->m_levelTime);
}
//============================================================================
/*This method handle in case of level up, update the states and reset the
clock level.*/
void GameState::levelup(int time) { 
	this->m_levelTime = sf::seconds((float)time);
	this->m_score += this->m_level * 50;
	++this->m_level;
	this->m_clock.restart();
}
//============================================================================
/*This method update the score after player collected a coin.*/
void GameState::collectedCoin() { this->m_score += this->m_level * 2; }
//============================================================================
/*This method handle in case of player is die- update lives and reset the 
clock level.*/
void GameState::died() {
	this->m_lifes--;
	this->m_clock.restart();
}
//============================================================================
/*This method handle in case of game is over. the method reset all the stats.*/
void GameState::gameOver() {
	this->m_level = 0;
	this->m_lifes = NUM_OF_LIFE;
	this->m_score = 0;
}
//============================================================================
/*This method checks if there is more lives to the player and return true
if doesnt.*/
bool GameState::isGameOver(){
	if (this->m_lifes <= 0)
		return true;
	return false;
}
//============================================================================
/*This method add time if the player collected a gift*/
void GameState::addTimeBonus() {
	if(this->m_levelTime.asSeconds() != NO_LEVEL_TIME)
		this->m_levelTime += sf::seconds(BONUS_TIME);
}
//============================================================================
/*This method add lives if the player collected a gift*/
void GameState::addLife() { this->m_lifes += BONUS_LIFE; }
//============================================================================
/*This method add score if the player collected a gift*/
void GameState::addScore() {
	this->m_score += BONUS_SCORE;
}
//============================== gets section ================================
sf::Vector2f GameState::getSize()const { 
	return this->m_background.getSize(); 
}
//============================================================================
sf::Vector2f GameState::getLocation()const {
	return this->m_background.getPosition();
}
//============================================================================
int GameState::getLevel()const { return this->m_level; }
//============================================================================
std::string GameState::getRemindMin() {
	if (this->m_levelTime.asSeconds() == NO_LEVEL_TIME)
		return std::to_string(NO_LEVEL_TIME);

	int time = (int)(((this->m_levelTime - this->m_clock.getElapsedTime())
		.asSeconds()) / 60.f);

	return std::to_string(time);
}
//============================================================================
std::string GameState::getRemindSec() {
	int time = ((int)(this->m_levelTime.asSeconds() - 
		this->m_clock.getElapsedTime().asSeconds()) % 60);
	for (int i = 0; time > 100; ++i)
		time /= 10;
	if (time < 10)
		return("0" + std::to_string(time));
	return (std::to_string(time));
}
//============================================================================