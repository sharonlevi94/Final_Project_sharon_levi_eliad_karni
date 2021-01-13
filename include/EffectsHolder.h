#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class EffectsHolder
{
public:
	~EffectsHolder();
	static const EffectsHolder& instance();

	const sf::Sound& getSound(int) const;
	const sf::Texture& getTexture(int)const;
	const sf::Font& getFont(int)const;
private:
	std::map<int, sf::Texture*> m_texture;
	std::map<int, sf::Sound*> m_sound;
	std::map<int, sf::Font*> m_font;

	EffectsHolder();
	
	void setBackgrounds();
	void setLogos();
	void setFonts();
	void setObjects();
};