#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class EffectsHolder
{
public:
	static EffectsHolder& instance();

	const sf::Sound& getSound(int) const;
	const sf::Texture& getBackground(int);
	const sf::Texture& getTexture(int)const;
	const sf::Font& getFont(int)const;
	void playMusic(int);
	void pauseMusic();

private:
	std::map<int, std::unique_ptr <sf::Texture>> m_texture;
	std::map<int, std::unique_ptr<sf::Sound>> m_sound;
	std::map<int, std::unique_ptr <sf::Font>> m_font;
	sf::Music m_music;

	EffectsHolder();
	
	void setBackgrounds();
	void setLogos();
	void setFonts();
	void setObjects();
	int m_backgroundLevelState;
};