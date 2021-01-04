//============================= include section ==============================
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"

#include <iostream>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Menu::Menu(const sf::Vector2f& size, const sf::Vector2f& location):
	m_location(location), m_size(size), temp_effects(EffectsHolder()){}
//============================== gets section ================================
//============================ methods section ===============================


void Menu::draw(sf::RenderWindow & window){
	//sprites and texts declerations
	sf::Sprite background;
	sf::Sprite logo;
	sf::Text startGame;
	sf::Text quit;

	float size = window.getSize().x / 2;
	background.setTexture(this->temp_effects.getTexture(MENU_BACKGROUND));
	logo.setTexture(this->temp_effects.getTexture(GAME_LOGO));
	
	logo.setScale(size / logo.getTexture()->getSize().x, size / logo.getTexture()->getSize().x);
	logo.setPosition(sf::Vector2f(
		((float)window.getSize().x - 
			(logo.getTexture()->getSize().x * logo.getScale().x))/2,
		((float)window.getSize().y) / 7
	));
	
	startGame.setString("START GAME!");
	quit.setString("QUIT GAME");
	startGame.setPosition(
		(window.getSize().x - startGame.getLocalBounds().width) / 2,
		logo.getPosition().y + logo.getTexture()->getSize().y);
	startGame.setFillColor(sf::Color::White);
	startGame.setFont(this->temp_effects.getFont(ARIRL_FONT));
	
	std::cout << '(' <<  window.getSize().x << " - " << startGame.getLocalBounds().width 
		<< ") / 2 = "<<  (window.getSize().x - startGame.getLocalBounds().width) / 2;
	window.draw(background);
	window.draw(logo);
	window.draw(startGame);
	sf::Font font;
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================