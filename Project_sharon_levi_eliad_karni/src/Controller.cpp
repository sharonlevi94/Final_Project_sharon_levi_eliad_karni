/*
   This file conatains all methods of the class Controller.
*/
//============================= include section ==============================
#include "Controller.h"
#include "Menu.h"
#include "Board.h"
#include "Coin.h"
#include "BadGift.h"
#include "ScoreGift.h"
#include "LifeGift.h"
#include "TimeGift.h"
#include "GameState.h"
#include "Resources.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Utilities.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Controller::Controller() :
	m_window(sf::VideoMode::getDesktopMode(), "Lode Runner",
		sf::Style::Fullscreen),
	m_board(sf::Vector2f(0, (float)this->m_window.getSize().y * 0.1f),
		sf::Vector2f((float)m_window.getSize().x, (float)m_window.getSize().y * (0.9f))),
	m_enemies({}),
	m_player(nullptr){
	m_giftEnemies.resize(0);
	this->m_menu = Menu(
		(sf::Vector2f)this->m_window.getSize(),
		sf::Vector2f(0, 0));
	this->m_gameState = GameState(sf::Vector2f(0, 0),
		sf::Vector2f((float)(this->m_window.getSize().x),
		this->m_window.getSize().y * 0.08f));
	srand((unsigned int)time(NULL));
}
/*============================ methods section ===============================
*
* this function run from the main function.
* open new window & run the menu screen.
* the user can click on and execute 2 options:
* "Play Game" - to start the game.
* "Quit" - for exit.
*/
void Controller::run() {
	while (true) {
		this->m_window.clear();
		char choose = this->runMenu();
		if (!this->m_window.isOpen() || choose == QUIT_GAME)
			break;
		if (choose == PLAY_GAME)
			this->runGame();
		if (!this->m_window.isOpen())
			break;
	}
}
/*============================ methods section ===============================
* the method handling bad gift collection case.
*/
void Controller::handleColision(BadGift& obj){
	if (!obj.is_collected()) {
		obj.collect();
		Resources::instance().playSound(DOOR_SOUND);
		this->m_giftEnemies.push_back(std::unique_ptr <Enemy>
			(raffleEnemy(this->m_board.getObjectSize(),
				this->m_board.getDoorLocation())));
	}
}
/*============================ methods section ===============================
* the method handling score gift collection case.
*/
void Controller::handleColision(ScoreGift& obj) {
	if (!obj.is_collected()) {
		obj.collect();
		this->m_gameState.addScore();
	}
}
/*============================================================================
* the method handling time gift collection case.
*/
void Controller::handleColision(TimeGift& obj) {
	if (!obj.is_collected()) {
		obj.collect();
		this->m_gameState.addTimeBonus();
	}
}
/*============================================================================
* the method handling life gift collection case.
*/
void Controller::handleColision(LifeGift& obj) {
	if (!obj.is_collected()) {
		obj.collect();
		this->m_gameState.addLife();
	}
}
/*============================================================================
* the method handling coin collection case.
*/
void Controller::handleColision(Coin& obj) {
	if (!obj.is_collected()) {
		obj.collect();
		Resources::instance().playSound(COIN_COLLECT_SOUND);
		this->m_gameState.collectedCoin();
	}
}
/*============================================================================
*
* this function run the menu screen and realize clicks by the user. 
* this function return the result of the click to the run function.
*/
char Controller::runMenu() {
	Resources::instance().playMusic(0);
	while (this->m_window.isOpen())
	{
		//displaying menu state
		this->m_window.clear();
		this->m_menu.draw(this->m_window);
		this->m_window.display();
		//recevive user movments
		sf::Event event{};
		while (this->m_window.waitEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				this->m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				switch (this->m_menu.handleClick(sf::Vector2f(
					(float)event.mouseButton.x, 
					(float)event.mouseButton.y))) {
				case PLAY_GAME:
					Resources::instance().pauseMusic();
					return PLAY_GAME;
				case QUIT_GAME:
					Resources::instance().pauseMusic();
					return QUIT_GAME;
					break;
				}
				break;
			default:
				if (this->m_menu.pointingHundle((sf::Vector2f)
					sf::Mouse::getPosition(this->m_window))) {
					this->m_menu.draw(this->m_window);
					this->m_window.display();
				}
				break;
			}

		}
	}
	Resources::instance().pauseMusic();
	return QUIT_GAME;
}
/*============================================================================
*
* this function is the central function that manage the proccess of the game.
* draw the objects, play their turns, check cilisions and load new levels.
* load new level if the player collected all the coins,
* finish the game if the player passed all the levels,
* reset level if the enemy catch the player,
* game over if the player is die.
*/
void Controller::runGame() {
	m_gameClock.restart();
	while (this->m_window.isOpen()){
		if (Coin::getCoinsCounter() == 0) {
			if (this->m_board.is_next_lvl_exist())
				this->levelup();
			else {
				this->gameOver();
				break;
			}
		}
		sf::Time deltaTime = m_gameClock.restart();
		this->m_window.clear();
		this->m_gameState.draw(this->m_window);
		this->m_board.draw(m_window, this->m_gameClock.getElapsedTime());
		this->drawObjects();
		this->m_window.display();

		if (this->m_gameState.isTimeUp())
			this->playerDied();
		this->play_turns(deltaTime);
		this->checkColisions();
		if (this->m_gameState.isGameOver() || 
			sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			this->gameOver();
			break;
		}
	}
}
//============================================================================
/*
* this function execute the turns of the characters. calculate their movements
* on the board.
*/
void Controller::play_turns(const sf::Time& deltaTime) {
	//playing movables turns.
	this->m_player->playTurn(deltaTime, this->m_board);
	this->enemiesTurns(deltaTime);
}
//============================================================================
/*
* this function execute the turns of the enemies. calculate their movements
* on the board.
*/
void Controller::enemiesTurns(const sf::Time& deltaTime) {
	for (int i = 0; i < this->m_enemies.size(); i++) {
		this->m_enemies[i]->playTurn(deltaTime, this->m_board);
	}
	for (int i = 0; i < this->m_giftEnemies.size(); i++)
		this->m_giftEnemies[i]->playTurn(deltaTime, this->m_board);
}
//============================================================================
/*
* this function draw all the dynamic objects in the game by the time clock.
*/
void Controller::drawObjects() {
	this->m_player->draw(this->m_window);
	for (int i = 0; i < this->m_enemies.size(); ++i)
		this->m_enemies[i]->draw(this->m_window);
	for (int i = 0; i < this->m_giftEnemies.size(); ++i)
		this->m_giftEnemies[i]->draw(this->m_window);
}
//============================================================================
/*
* this function get a vector of MovingObject & seperate the player from the 
* enemies. the function save the player as a member and the enemies in vector.
*/
void Controller::seperateGameObjects(const vector<MovingObject*>& list) {
	this->m_enemies.clear();
	for (int i = 0; i < list.size(); ++i) {
		if (dynamic_cast <Player*> (list[i]))
			this->m_player = (Player*)list[i];
		else
			this->m_enemies.push_back(list[i]);
	}
}
//============================================================================
/*
* this function handle in case while the player catched by the enemy.
* then it reset the level board, update the game state and clear all the 
* additional enemies.
*/
void Controller::playerDied(){
	//reset Static objects:
	Resources::instance().playSound(ENEMY_SOUND);
	this->m_board.resetLvl(); 
	this->m_giftEnemies.clear();
	this->m_gameState.died();
}
//============================================================================
/*
* this function handle in case while the player is dead. 
*/
void Controller::gameOver() {
	//TODO: Game Over msg
	Resources::instance().pauseMusic();
	this->m_player = nullptr;
	this->m_enemies.clear();
	this->m_board.gameOver();
	this->m_gameState.gameOver();
	this->m_giftEnemies.clear();
}
//============================================================================
/*
* this function check coliosion between the characters and the collectable 
* objects.
*/
void Controller::checkColisions() {
	this->checkCoinsColisions();
	this->checkCollectableColisions();
	this->checkEnemiesColisions();
}
//============================================================================
/*
* this function check coliosion between the enemies to the player.
*/
void Controller::checkEnemiesColisions() {
	for (int i = 0; i < this->m_enemies.size(); i++)
		if (this->m_player->CollidesWith(*this->m_enemies[i])&&
			!this->m_enemies[i]->getTrapState()) {
			this->playerDied();
			return;
		}
	for (int i = 0; i < this->m_giftEnemies.size(); i++)
		if (this->m_player->CollidesWith(*this->m_giftEnemies[i])) {
			this->playerDied();
		}
}
//============================================================================
/*
* this function check coliosion between the player to the gifts.
*/
void Controller::checkCollectableColisions() {
	if (dynamic_cast <CollectableObject*> (this->m_board.getContent(this->
	m_player->getCenter()))) {
			((CollectableObject*)this->m_board.getContent(this->m_player->
			getCenter()))->handleColision(*this);
		}
	}
//============================================================================
/*
* this function check coliosion between the player to the coins.
*/
void Controller::checkCoinsColisions() {
	if (dynamic_cast <Coin*> (this->m_board.getContent(this->m_player->
		getCenter()))) {
		if (!((Coin*)this->m_board.getContent(this->m_player->getCenter()))->
			is_collected()) {
		}
	}
}
//============================================================================
/*
* this function handle in case of player finished the current level.
* hte function load new level, and update all the states, effects & music.
*/
void Controller::levelup() {
	this->m_giftEnemies.clear();
	Resources::instance().pauseMusic();
	srand((unsigned int)time(NULL));
	this->seperateGameObjects(this->m_board.loadNewLevel());
	this->m_gameState.levelup(this->m_board.getLevelTime());
	this->m_board.loadLevelEffects(this->m_gameState.getLevel());
}
//============================================================================
/*
* this function handle the case of the player is catched by the enemy, 
* the function clear all the additional enemies and return the enemies
* to their initial locations.
*/
void Controller::resetLvl() {
	for (int i = 0; i < this->m_enemies.size(); ++i)
		this->m_enemies[i]->reset();
	this->m_giftEnemies.clear();
}