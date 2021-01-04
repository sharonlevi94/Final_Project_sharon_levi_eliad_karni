//============================= include section ==============================
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
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

	//background.setTexture(this->temp_effects.getTexture(MENU_BACKGROUND));
	logo.setTexture(this->temp_effects.getTexture(GAME_LOGO));
	logo.setPosition(sf::Vector2f(
		((float)window.getSize().x)/2,
		((float)window.getSize().y)/2
	));
	logo.setScale(500,500);

	//window.draw(background);
	window.draw(logo);
	sf::Font font;
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================