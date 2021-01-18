//============================= include section ==============================
#include "EffectsHolder.h"
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
EffectsHolder::EffectsHolder() {
	this->m_texture.clear();
	this->m_sound.clear();
	this->m_font.clear();

	this->setBackgrounds();
	this->setLogos();
	this->setFonts();
	this->setObjects();
}
EffectsHolder& EffectsHolder::instance() {
	static EffectsHolder inst;
	return(inst);
}
//============================== gets section ================================
//============================================================================
const sf::Texture& EffectsHolder::getBackground(int textureKey){
if(textureKey != this->m_backgroundLevelState){
		switch(textureKey){
		case 1:
			this->m_texture[LEVEL_BACKGROUND]->
				loadFromFile(LEVEL1_BACKGROUND_PATH);
			break;
		case 2:
			this->m_texture[LEVEL_BACKGROUND]->
				loadFromFile(LEVEL2_BACKGROUND_PATH);
			break;
		case 3:
			this->m_texture[LEVEL_BACKGROUND]->
				loadFromFile(LEVEL3_BACKGROUND_PATH);
			break;
		case 4:
			this->m_texture[LEVEL_BACKGROUND]->
				loadFromFile(LEVEL4_BACKGROUND_PATH);
			break;
		}
		this->m_backgroundLevelState = textureKey;
	}
	return (*this->m_texture.find(LEVEL_BACKGROUND)->second);
}
//============================================================================
const sf::Texture& EffectsHolder::getTexture(int textureKey)const{
	return (*this->m_texture.find(textureKey)->second);
}
//============================================================================
const sf::Sound& EffectsHolder::getSound(int soundKey) const{
	return(*this->m_sound.find(soundKey)->second);
}
//============================================================================
const sf::Font& EffectsHolder::getFont(int fontKey) const{
	return(*this->m_font.find(fontKey)->second);
}
//============================================================================
void EffectsHolder::playMusic(int levelNumber) {
	switch (levelNumber)
	{
	case 0:
		this->m_music.openFromFile();
		break;
	default:
		break;
	}
	
}
//============================ methods section ===============================
//============================ private section ===============================
//============================== sets section ================================
//============================ methods section ===============================
//============================================================================
void EffectsHolder::setBackgrounds(){
	std::unique_ptr<sf::Texture> texturesCreator;
	//adding game's backgrounds path
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(MENU_BACKGROUND, std::move(texturesCreator)));
	this->m_texture[MENU_BACKGROUND]->loadFromFile(MENU_BACKGROUND_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(GAME_STATE,  std::move(texturesCreator)));
	this->m_texture[GAME_STATE]->loadFromFile(GAME_STATE_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(LEVEL_BACKGROUND, std::move(texturesCreator)));
	//adding levels background path
}
//============================================================================
void EffectsHolder::setLogos() {
	std::unique_ptr<sf::Texture> texturesCreator;
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(GAME_LOGO, std::move(texturesCreator)));
	this->m_texture[GAME_LOGO]->loadFromFile(GAME_LOGO_PATH);
}
//============================================================================
void EffectsHolder::setFonts(){
	std::unique_ptr<sf::Font> fontsCreator;
	fontsCreator = std::make_unique<sf::Font>();
	this->m_font.insert(std::pair<int, std::unique_ptr <sf::Font>>
		(ARIEL_FONT, std::move(fontsCreator)));
	this->m_font[ARIEL_FONT]->loadFromFile(ARIEL_FONT_PATH);
}
//============================================================================
void EffectsHolder::setObjects() {
	std::unique_ptr<sf::Texture> texturesCreator;

	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(PLAYER_T, std::move(texturesCreator)));
	this->m_texture[PLAYER_T]->loadFromFile(PLAYER_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(ENEMY_T, std::move(texturesCreator)));
	this->m_texture[ENEMY_T]->loadFromFile(ENEMY_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(COIN_T, std::move(texturesCreator)));
	this->m_texture[COIN_T]->loadFromFile(COIN_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(WALL_T, std::move(texturesCreator)));
	this->m_texture[WALL_T]->loadFromFile(WALL_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(LADDER_T, std::move(texturesCreator)));
	this->m_texture[LADDER_T]->loadFromFile(LADDER_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(ROD_T, std::move(texturesCreator)));
	this->m_texture[ROD_T]->loadFromFile(ROD_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(GIFT_T, std::move(texturesCreator)));
	this->m_texture[GIFT_T]->loadFromFile(GIFT_PATH);
	//------------------------------------------------------------------------
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(DOOR_T, std::move(texturesCreator)));
	this->m_texture[DOOR_T]->loadFromFile(DOOR_PATH);
}