//============================= include section ==============================
#include "EffectsHolder.h"
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
EffectsHolder::EffectsHolder() {
	this->m_texture = {};
	this->setBackgrounds();
	this->setLogos();
	this->setFonts();
	this->setObjects();
}
//----------------------------------------------------------------------------
EffectsHolder::~EffectsHolder(){
	//delete textures allocations
	for (auto iterator = this->m_texture.begin(); 
		iterator != this->m_texture.end(); ++iterator)
		delete(iterator->second);
	//delete sounds allocations
	for (auto iterator = this->m_sound.begin(); 
		iterator != this->m_sound.end(); ++iterator)
		delete(iterator->second);
	//delete fonts allocations
	for (auto iterator = this->m_font.begin(); 
		iterator != this->m_font.end(); ++iterator)
		delete(iterator->second);
}
//============================== gets section ================================
const sf::Texture& EffectsHolder::getTexture(int textureKey)const{
	return (*this->m_texture.find(textureKey)->second);
}
//----------------------------------------------------------------------------
const sf::Sound& EffectsHolder::getSound(int soundKey) const{
	return(*this->m_sound.find(soundKey)->second);
}
//----------------------------------------------------------------------------
const sf::Font& EffectsHolder::getFont(int fontKey) const{
	return(*this->m_font.find(fontKey)->second);
}
//============================ methods section ===============================

//============================ private section ===============================
//============================== sets section ================================
//============================ methods section ===============================
//============================================================================
void EffectsHolder::setBackgrounds(){
	//adding menu background path
	this->m_texture.insert(std::pair<int, sf::Texture*>
		(MENU_BACKGROUND, new sf::Texture));
	this->m_texture[MENU_BACKGROUND]->loadFromFile(MENU_BACKGROUND_PATH);
	//adding level1 background path
	this->m_texture.insert(std::pair<int, sf::Texture*>
		(LEVEL1, new sf::Texture));
	this->m_texture[LEVEL1]->loadFromFile(LEVEL1_BACKGROUND_PATH);
}
//============================================================================
void EffectsHolder::setLogos() {
	this->m_texture.insert(std::pair<int, sf::Texture*>
		(GAME_LOGO, new sf::Texture));
	this->m_texture[GAME_LOGO]->loadFromFile(GAME_LOGO_PATH);
}
//============================================================================
void EffectsHolder::setFonts(){
	this->m_font.insert(std::pair<int, sf::Font*>
		(ARIRL_FONT, new sf::Font));
	this->m_font[ARIRL_FONT]->loadFromFile(ARIEL_FONT_PATH);
}
//----------------------------------------------------------------------------
void EffectsHolder::setObjects() {

}