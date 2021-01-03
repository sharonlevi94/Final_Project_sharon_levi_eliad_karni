#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class EffectsHolder
{
public:
	EffectsHolder();
	sf::Sound* getSound(int) const;
	sf::Texture* getTexture(int)const;

private:
	std::map<int, sf::Texture*> m_texture;
	std::map<int, sf::Sound*> m_sound;
};

123123