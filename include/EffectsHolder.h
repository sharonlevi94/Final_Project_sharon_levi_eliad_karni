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
	vector<sf::Sprite*> m_levelSprites;
	vector<sf::Sprite*> m_objectSprites;
	vector<sf::Sound> m_sounds;
	sf::Vector2f size;
};