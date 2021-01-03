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
	vector<sf::Texture> m_levelTexturs;
	//vector<sf::Sprite> m_playerSprites;
	//vector<sf::Sprite> m_enemySprites;
	//vector<sf::Sprite> m_coinSprites;
	//vector<sf::Sprite> m_wallSprites;
	//vector<sf::Sprite> m_ladderSprites;
	//vector<sf::Sprite> m_giftSprites;
	vector<sf::Sound> m_sounds;
	vector<sf::Music> m_menuMusic;
	vector<sf::Music> m_levelMusic;
	sf::Vector2f size;
};