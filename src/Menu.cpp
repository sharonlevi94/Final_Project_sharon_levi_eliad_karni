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
	sf::Sprite background;
	background.setTexture(this->temp_effects.getTexture(MENU_BACKGROUND));
	window.draw(background);
	sf::Font font;
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================