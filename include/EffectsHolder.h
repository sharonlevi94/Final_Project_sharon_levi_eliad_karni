#ifndef _EFFECTSHOLDER_H_
#define _EFFECTSHOLDER_H_
#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class EffectsHolder
{
public:
	EffectsHolder();
	~EffectsHolder();

	const sf::Sound& getSound(int) const;
	const sf::Texture& getTexture(int)const;
	const sf::Font& getFont(int)const;

private:
	std::map<int, sf::Texture*> m_texture;
	std::map<int, sf::Sound*> m_sound;
	std::map<int, sf::Font*> m_font;

	void setBackgrounds();
	void setLogos();
	void setFonts();
	void setObjects();
};
#endif //_EFFECTSHOLDER_H_