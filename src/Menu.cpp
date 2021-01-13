//============================= include section ==============================
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "EffectsHolder.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Menu::Menu(const sf::Vector2f& size,
	const sf::Vector2f& location) :
	m_location(location), m_size(size), m_startGameButton(sf::Text()),
	m_quitGameButton(sf::Text()), m_GameLogo(sf::Sprite()){
	calcLogo();
	calcStartButton();
	calcQuitButton();
	calcBackground();
}
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Menu::draw(sf::RenderWindow & window){
	window.draw(this->m_background);
	window.draw(this->m_GameLogo);
	window.draw(this->m_startGameButton);
	window.draw(this->m_quitGameButton);
}
//============================================================================
char Menu::handleClick(const sf::Vector2f& location) const{
	if (this->m_startGameButton.getGlobalBounds().contains(location))
		return('s');
	if (this->m_quitGameButton.getGlobalBounds().contains(location))
		return('q');
	return('n');
}
//============================================================================
bool Menu::pointingHundle(const sf::Vector2f& location) {
	bool changed = false;
	if (this->m_startGameButton.getGlobalBounds().contains(location)) {
		if (this->m_startGameButton.getFillColor() != sf::Color::Yellow) {
			this->m_startGameButton.setFillColor(sf::Color::Yellow);
			this->m_startGameButton.setOutlineThickness(2);
			changed = true;
		}
	}
	else if (this->m_startGameButton.getFillColor() != sf::Color::White) {
		this->m_startGameButton.setFillColor(sf::Color::White);
		this->m_startGameButton.setOutlineThickness(0);
		changed = true;
	}
	
	if (this->m_quitGameButton.getGlobalBounds().contains(location)) {
		if (this->m_quitGameButton.getFillColor() != sf::Color::Yellow) {
			this->m_quitGameButton.setFillColor(sf::Color::Yellow);
			this->m_quitGameButton.setOutlineThickness(2);
			changed = true;
		}
	}
	else if (this->m_quitGameButton.getFillColor() != sf::Color::White) {
		this->m_quitGameButton.setFillColor(sf::Color::White);
		this->m_quitGameButton.setOutlineThickness(0);
		changed = true;
	}
	return(changed);
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================
//============================================================================
void Menu::calcLogo() {
	this->m_GameLogo.setTexture(EffectsHolder::instance().
		getTexture(GAME_LOGO));
	this->m_GameLogo.setScale((float)(this->m_size.x / 2) /
		this->m_GameLogo.getTexture()->getSize().x,
		(float)this->m_size.x / 2 / this->m_GameLogo.getTexture()
		->getSize().x);
	
	this->m_GameLogo.setPosition(sf::Vector2f(
		(this->m_size.x -
		(this->m_GameLogo.getTexture()->getSize().x 
			* this->m_GameLogo.getScale().x)) / 2,
		((float)this->m_size.y) / 7));
}
//============================================================================
void Menu::calcStartButton() {
	this->m_startGameButton.setString("START GAME!");
	this->m_startGameButton.setFont(EffectsHolder::instance()
		.getFont(ARIEL_FONT));
	this->m_startGameButton.setFillColor(sf::Color::White);
	this->m_startGameButton.setOutlineColor(sf::Color::Black);

	this->m_startGameButton.setScale((float)(this->m_size.x / 2) /
		this->m_GameLogo.getTexture()->getSize().x,
		(float)this->m_size.x / 2 / this->m_GameLogo.getTexture()
		->getSize().x);

	this->m_startGameButton.setPosition(
		(this->m_size.x -
		(this->m_startGameButton.getLocalBounds().width
			* this->m_GameLogo.getScale().x)) / 2,
		this->m_GameLogo.getPosition().y + this->m_GameLogo.getTexture()
		->getSize().y * this->m_GameLogo.getScale().y +
		this->m_size.y / 15);
}
//============================================================================
void Menu::calcQuitButton(){
	this->m_quitGameButton.setString("QUIT GAME");
	this->m_quitGameButton.setFont(EffectsHolder::instance()
		.getFont(ARIEL_FONT));
	this->m_quitGameButton.setFillColor(sf::Color::White);
	this->m_quitGameButton.setOutlineColor(sf::Color::Black);

	this->m_quitGameButton.setScale((float)(this->m_size.x / 2) /
		this->m_GameLogo.getTexture()->getSize().x,
		(float)this->m_size.x / 2 / this->m_GameLogo.getTexture()
		->getSize().x);

	this->m_quitGameButton.setPosition(
		(this->m_size.x -
			(this->m_quitGameButton.getLocalBounds().width
				* this->m_startGameButton.getScale().x)) / 2,

		this->m_startGameButton.getPosition().y + 
		this->m_startGameButton.getLocalBounds().height * 
		this->m_startGameButton.getScale().y +
		this->m_size.y / 15);
}
//============================================================================
void Menu::calcBackground() {
	this->m_background.setTexture(EffectsHolder::instance()
		.getTexture(MENU_BACKGROUND));
	
	this->m_background.scale(this->m_size.x / 
		this->m_background.getTexture()->getSize().x,
		this->m_size.y / this->m_background.getTexture()->getSize().y);
}