#pragma once
//============================ include section ===============================
#include <vector>
#include "DataReader.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class MovingObject;
class GameObject;
class Enemy;
class Gift;
class Door;
class Player;

using std::vector;
class Board
{
public:
	Board(const sf::Vector2f& location = sf::Vector2f(0,0),
		const sf::Vector2f& size = sf::Vector2f(0,0));
	~Board();

	void draw(sf::RenderWindow& window, const sf::Time&);
	vector<MovingObject*>loadNewLevel();
	bool is_next_lvl_exist()const;
	int getLevelTime()const;
	sf::Vector2f getlevelSize()const;
	const sf::Vector2f& getLocation() const;
	GameObject* getContent(const sf::Vector2f& location);
	const GameObject* getContent(const sf::Vector2f&) const;
	void resetLvl();
	void gameOver();
	
	const sf::Vector2f& getDoorLocation()const;
	bool isMovePossible(const sf::Vector2f&)const;
	const sf::Vector2f& getPlayerLoc()const;
	void loadLevelEffects(int);
private:
	vector<vector<std::unique_ptr<GameObject>>> m_map;
	sf::Vector2f m_levelSize;
	sf::Vector2f m_location;
	DataReader m_levelReader;
	sf::RectangleShape m_background;
	std::unique_ptr <Door> m_door;
	Player* m_player;

	void releaseMap();
	void clearParameters();
	Gift* raffleGift(const sf::Vector2f& boxSize,
		const sf::Vector2i& index);
	Enemy* raffleEnemy(const sf::Vector2f&, const sf::Vector2i&);
};