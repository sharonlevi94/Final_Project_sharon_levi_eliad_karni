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
	//adding menu background path
	this->m_texture.insert(std::pair<int, sf::Texture*>
		(MENU_BACKGROUND, new sf::Texture));
	this->m_texture[MENU_BACKGROUND]->loadFromFile(MENU_BACKGROUND_PATH);
}

//============================== gets section ================================
sf::Texture* EffectsHolder::getTexture(int textureKey) const{
	return(this->m_texture[textureKey]);
}
sf::Sound* EffectsHolder::getSound(int soundKey) const{
	return(this->m_sound[soundKey]);
}
//============================ methods section ===============================

//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================