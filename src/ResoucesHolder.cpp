//============================= include section ==============================
#include "ResoucesHolder.h"
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
ResoucesHolder::ResoucesHolder():
m_music(){
	this->m_texture.clear();
	this->m_soundBuffers.clear();
	this->m_font.clear();
	this->m_music.setVolume(MUSIC_VOLUME);
	this->m_NumOfSprites.clear();

	this->setBackgrounds();
	this->setLogos();
	this->setFonts();
	this->setObjects();
	this->setSounds();
	this->setNumOfSprites();
}
//============================================================================
ResoucesHolder& ResoucesHolder::instance() {
	static ResoucesHolder inst;
	return(inst);
}
//============================== gets section ================================
//============================================================================
const sf::Texture& ResoucesHolder::getBackground(int textureKey){
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
const sf::Texture& ResoucesHolder::getTexture(int textureKey)const{
	return (*this->m_texture.find(textureKey)->second);
}
//============================================================================
const sf::SoundBuffer& ResoucesHolder::getSound(int soundKey) const{
	return(*this->m_soundBuffers.find(soundKey)->second);
}
//============================================================================
const sf::Font& ResoucesHolder::getFont(int fontKey) const{
	return(*this->m_font.find(fontKey)->second);
}
//============================================================================
const int ResoucesHolder::getNumOfSprites(int key)const{
	return (this->m_NumOfSprites.find(key)->second);
}
//============================================================================
void ResoucesHolder::playMusic(int levelNumber) {
	switch (levelNumber)
	{
	case 0:
		this->m_music.openFromFile(MENU_MUSIC_PATH);
		break;
	case 1:
		this->m_music.openFromFile(LEVEL1_MUSIC_PATH);
		break;
	case 2:
		this->m_music.openFromFile(LEVEL2_MUSIC_PATH);
		break;
	case 3:
		this->m_music.openFromFile(LEVEL3_MUSIC_PATH);
		break;
	case 4:
		this->m_music.openFromFile(LEVEL4_MUSIC_PATH);
		break;
	}
	this->m_music.play();
	this->m_music.setLoop(true);
}
//============================================================================
void ResoucesHolder::pauseMusic() { this->m_music.pause(); }
//============================ methods section ===============================
//============================ private section ===============================
//============================== sets section ================================
void ResoucesHolder::setBackgrounds(){
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
void ResoucesHolder::setLogos() {
	std::unique_ptr<sf::Texture> texturesCreator;
	texturesCreator = std::make_unique<sf::Texture>();
	this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
		(GAME_LOGO, std::move(texturesCreator)));
	this->m_texture[GAME_LOGO]->loadFromFile(GAME_LOGO_PATH);
}
//============================================================================
void ResoucesHolder::setFonts(){
	std::unique_ptr<sf::Font> fontsCreator;
	fontsCreator = std::make_unique<sf::Font>();
	this->m_font.insert(std::pair<int, std::unique_ptr <sf::Font>>
		(ARIEL_FONT, std::move(fontsCreator)));
	this->m_font[ARIEL_FONT]->loadFromFile(ARIEL_FONT_PATH);
}
//============================================================================
void ResoucesHolder::setObjects() {
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
//============================================================================
void ResoucesHolder::setSounds() {
	std::unique_ptr<sf::SoundBuffer> soundsCreator;
	//------------------------------------------------------------------------
	soundsCreator = std::make_unique<sf::SoundBuffer>();
	this->m_soundBuffers.insert(std::pair<int, std::unique_ptr <sf::SoundBuffer>>
		(DIGGING_SOUND, std::move(soundsCreator)));
	this->m_soundBuffers[DIGGING_SOUND]->loadFromFile(DIG_SOUND_PATH);

	soundsCreator = std::make_unique<sf::SoundBuffer>();
	this->m_soundBuffers.insert(std::pair<int, std::unique_ptr <sf::SoundBuffer>>
		(COIN_COLLECT_SOUND, std::move(soundsCreator)));
	this->m_soundBuffers[COIN_COLLECT_SOUND]->loadFromFile(COINS_SOUND_PATH);

	soundsCreator = std::make_unique<sf::SoundBuffer>();
	this->m_soundBuffers.insert(std::pair<int, std::unique_ptr <sf::SoundBuffer>>
		(FALLING_SOUND, std::move(soundsCreator)));
	this->m_soundBuffers[FALLING_SOUND]->loadFromFile(FALLING_SOUND_PATH);

	soundsCreator = std::make_unique<sf::SoundBuffer>();
	this->m_soundBuffers.insert(std::pair<int, std::unique_ptr <sf::SoundBuffer>>
		(DOOR_SOUND, std::move(soundsCreator)));
	this->m_soundBuffers[DOOR_SOUND]->loadFromFile(DOOR_SOUND_PATH);

	soundsCreator = std::make_unique<sf::SoundBuffer>();
	this->m_soundBuffers.insert(std::pair<int, std::unique_ptr <sf::SoundBuffer>>
		(STEP_SOUND, std::move(soundsCreator)));
	this->m_soundBuffers[STEP_SOUND]->loadFromFile(STEP_SOUND_PATH);

	soundsCreator = std::make_unique<sf::SoundBuffer>();
	this->m_soundBuffers.insert(std::pair<int, std::unique_ptr <sf::SoundBuffer>>
		(ENEMY_SOUND, std::move(soundsCreator)));
	this->m_soundBuffers[ENEMY_SOUND]->loadFromFile(ENEMY_SOUND_PATH);

}
//============================ methods section ===============================
void ResoucesHolder::playSound(int key) {
	m_sound.setBuffer(this->getSound(key));
	m_sound.play();
}
//============================================================================
void ResoucesHolder::setNumOfSprites(){
	this->m_NumOfSprites.insert(std::pair<int, int>(STAND, NUM_OF_STAND_SPRITE));
	this->m_NumOfSprites.insert(std::pair<int, int>(CLIMBING, NUM_OF_CLIMB_SPRITE));
	this->m_NumOfSprites.insert(std::pair<int, int>(RUNNING, NUM_OF_RUNNING_SPRITE));
	this->m_NumOfSprites.insert(std::pair<int, int>(RODDING, NUM_OF_RODDING_SPRITE));
	this->m_NumOfSprites.insert(std::pair<int, int>(FALLING,NUM_OF_FALLING_SPRITE));
}