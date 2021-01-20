#pragma once
//============================ include section ===============================
#include "Board.h"
#include "Menu.h"
#include "Enemy.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
//========================== forward declarations ============================
class MovingObject;
class Player;
class BadGift;
class ScoreGift;
class TimeGift;
class LifeGift;

class Controller
{
public:
	Controller();

	void run();

	void handleColision(const BadGift&);
	void handleColision(const ScoreGift&);
	void handleColision(const TimeGift&);
	void handleColision(const LifeGift&);

private:
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	GameState m_gameState;
	vector <MovingObject*> m_enemies;
	std::vector<std::unique_ptr<Enemy>> m_giftEnemies;
	Player* m_player;
	sf::Clock m_gameClock;

	void runGame();
	char runMenu();

	void enemiesTurns(const sf::Time&);
	void play_turns(const sf::Time&);
	void drawObjects();
	void checkColisions();
	void checkEnemiesColisions();
	void checkCoinsColisions();
	void checkGiftsColisions();

	void seperateGameObjects(const vector<MovingObject*>&);

	void playerDied();
	void levelup();
	void resetLvl();
	void gameOver();
};