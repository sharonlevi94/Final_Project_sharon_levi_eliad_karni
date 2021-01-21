#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class EffectsHolder
{
public:
	static EffectsHolder& instance();

	const sf::SoundBuffer& getSound(int) const;
	void playSound(int key);
	const sf::Texture& getBackground(int);
	const sf::Texture& getTexture(int)const;
	const sf::Font& getFont(int)const;
	const int getNumOfSprites(int)const;
	void playMusic(int);
	void pauseMusic();

private:
	std::map<int, std::unique_ptr <sf::Texture>> m_texture;
	std::map<int, int> m_NumOfSprites;
	std::map<int, std::unique_ptr<sf::SoundBuffer>> m_soundBuffers;
	std::map<int, std::unique_ptr <sf::Font>> m_font;
	sf::Music m_music;
	sf::Sound m_sound;

	EffectsHolder();
	
	void setBackgrounds();
	void setLogos();
	void setFonts();
	void setObjects();
	void setSounds();
	void setNumOfSprites();
	int m_backgroundLevelState;
};