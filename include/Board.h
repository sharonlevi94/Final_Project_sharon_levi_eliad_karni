#pragma once
#include <vector>
#include "GameObjects.h"
#include "MovingObjects.h"
#include "DataReader.h"
#include "EffectsHolder.h"
#include <SFML/Graphics.hpp>

using std::vector;
class Board
{
public:
	Board();

	void draw(const EffectsHolder&)    const;
	vector<MovingObjects*> resetLevel()const;
	vector<GameObjects*> loadLevel();
	bool is_lvl_over()                 const;
	GameObjects* getContent()          const;

private:
	vector<vector<GameObjects*>> m_map;
	sf::Vector2f m_size;
	sf::Vector2f m_location;
	vector<Coin*> m_coins;
	DataReader m_levelReader;
};