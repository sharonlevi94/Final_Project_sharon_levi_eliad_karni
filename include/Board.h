#pragma once
#include <vector>
#include "GameObject.h"
#include "DataReader.h"
#include "EffectsHolder.h"
#include <SFML/Graphics.hpp>
using std::vector;

class Board
{
public:
	Board(sf::Vector2u, const EffectsHolder&);
	~Board();

	void draw(sf::RenderWindow& window)const;
	void loadNewLevel(const EffectsHolder&);
	bool is_next_lvl_exist()const;
	bool is_time_lvl_exist()const;
	const GameObject* getContent(const sf::Vector2f& location)const;
	int getLevelTime()const;
	

private:
	vector<vector<GameObject*>> m_map;
	sf::Vector2f m_backgroundSize;
	sf::Vector2f m_levelSize;
	sf::Vector2f m_location;
	DataReader m_levelReader;
	int m_levelTime;
	bool m_timeLimit;
	sf::RectangleShape m_background;
	EffectsHolder m_effectsHolder;
	int m_levelNumber;
};