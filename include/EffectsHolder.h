#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using std::vector;
class EffectsHolder
{
public:
	EffectsHolder(const sf::Vector2f& Size = sf::Vector2f(0,0));

	void loadEffects();
	const sf::Sound& getSound(int) const;
	const sf::Sprite& getsprite(char)const;
	const sf::Sprite& getlevelSprite(int)const;

private:
	vector<sf::Sprite*> m_levelSprites;
	vector<sf::Sprite*> m_objectSprites;
	vector<sf::Sound> m_sounds;
	sf::Vector2f size;
};