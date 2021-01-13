#pragma once
//============================ include section ===============================
#include <vector>
#include "DataReader.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class MovingObject;
class GameObject;

using std::vector;
class Board
{
public:
	Board(const sf::Vector2f& location = sf::Vector2f(0,0),
		const sf::Vector2f& size = sf::Vector2f(0,0));
	~Board();

	void draw(sf::RenderWindow& window)const;
	std::vector<MovingObject*> loadNewLevel();
	bool is_next_lvl_exist()const;
	int getLevelTime()const;
	vector<MovingObject*> FindMovingObj();
	sf::Vector2f getlevelSize()const;
	const sf::Vector2f& getLocation() const;
	GameObject* getContent(const sf::Vector2f location)const;
	void resetLvl();
	void gameOver();
	bool isAllCoinsCollected()const;
	
	int getMovmentSpeed()const;
	bool isMovePossible(const sf::Vector2f&)const;
private:
	vector<vector<GameObject*>> m_map;
	sf::Vector2f m_backgroundSize;
	sf::Vector2f m_levelSize;
	sf::Vector2f m_location;
	DataReader m_levelReader;
	int m_levelTime;
	sf::RectangleShape m_background;
	int m_levelNumber;

	void releaseMap();
};