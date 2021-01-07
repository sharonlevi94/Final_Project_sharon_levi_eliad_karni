#ifndef _BOARD_H_
#define _BOARD_H_
#pragma once
#include <vector>
#include "MovingObject.h"
#include "GameObject.h"
#include "DataReader.h"
#include "EffectsHolder.h"
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board(const sf::Vector2f& location = sf::Vector2f(0, 0),
		const sf::Vector2f& size = sf::Vector2f(0, 0),
		const EffectsHolder& effects = EffectsHolder());
	
	void draw(sf::RenderWindow&)const;
	std::vector<MovingObject*> loadNewLevel(const EffectsHolder&);
	bool is_next_lvl_exist()const;
	sf::Vector2f getlevelSize()const;
	const sf::Vector2f& getLocation() const;
	int getLevelTime()const;

private:
	std::vector<std::vector<GameObject*>> m_map;
	sf::Vector2f m_levelSize;
	sf::Vector2f m_location;
	DataReader m_levelReader;
	sf::Sprite m_background;

	void releaseMap();
};
#endif //_BOARD_H_