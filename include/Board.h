#pragma once
#include <vector>
#include "GameObject.h"
#include "MovingObject.h"
#include "DataReader.h"
#include "EffectsHolder.h"
#include "Coin.h"
#include <SFML/Graphics.hpp>
using std::vector;

class Board
{
public:
	Board(sf::Vector2u);
	//~Board();

	void draw(sf::RenderWindow& window)const;
	void loadNewLevel(/* sf::Texture* */);
	//bool is_next_lvl_exist()const;
	bool is_time_lvl_exist()const;
	//const GameObject* getContent(const sf::Vector2f& location)const;
	int getLevelTime()const;
	

private:
	//vector<vector<GameObject*>> m_map;
	sf::Vector2f m_size;
	sf::Vector2f m_location;
	//DataReader m_levelReader;
	int m_levelTime;
	bool m_timeLimit;
	sf::RectangleShape m_background;
	EffectsHolder m_effectsHolder;
	int m_levelNumber;
};