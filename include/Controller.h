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
/*============================================================================
* Class: Controller. 
* This class manage the game. handle all the cases that happen in the game.
* it connect between all the classes in the project.
* it can load the levels, play the turns,handle colisions
* and draw the objects of the game.
 ============================================================================*/
class Controller
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
	Controller();
	//=========================== method section =============================
	void run();
	void handleColision(Coin&);
	void handleColision(BadGift&);
	void handleColision(ScoreGift&);
	void handleColision(TimeGift&);
	void handleColision(LifeGift&);
	//========================= private section ==============================
private:
	//========================= members section ==============================
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	GameState m_gameState;
	vector <MovingObject*> m_enemies;
	std::vector<std::unique_ptr<Enemy>> m_giftEnemies;
	Player* m_player;
	sf::Clock m_gameClock;
	//====================== privete methods section =========================
	void runGame();
	char runMenu();

	void enemiesTurns(const sf::Time&);
	void play_turns(const sf::Time&);
	void drawObjects();
	void checkColisions();
	void checkEnemiesColisions();
	void checkCoinsColisions();
	void checkCollectableColisions();

	void seperateGameObjects(const vector<MovingObject*>&);

	void playerDied();
	void levelup();
	void resetLvl();
	void gameOver();
};
