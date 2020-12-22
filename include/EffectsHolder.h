#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using std::vector;
class EffectsHolder
{
public:
	EffectsHolder();

	void loadEffects();
	const sf::Sound& getSound(int) const;
	const sf::Texture& getTexture(char)const;

private:
	vector<sf::Texture> m_textures;
	vector<sf::Sound> m_sounds;
};