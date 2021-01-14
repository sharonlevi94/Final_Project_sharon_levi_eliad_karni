//============================= include section ==============================
#include "Controller.h"
#include "Menu.h"
#include "Board.h"
#include "Coin.h"
#include "GameState.h"
#include "EffectsHolder.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Controller::Controller() :
	m_window(sf::VideoMode::getDesktopMode(), "Lode Runner",
		sf::Style::Fullscreen),
	m_board(sf::Vector2f(0, (float)this->m_window.getSize().y * 0.1f),
		sf::Vector2f((float)m_window.getSize().x, (float)m_window.getSize().y * (0.9f))),
	m_enemies({}),
	m_player(nullptr){
	this->m_menu = Menu(
		(sf::Vector2f)this->m_window.getSize(),
		sf::Vector2f(0, 0));
	this->m_gameState = GameState(sf::Vector2f(0, 0),
		sf::Vector2f((float)(this->m_window.getSize().x),
		this->m_window.getSize().y * 0.08f));
}
//============================== gets section ================================
//============================ methods section ===============================
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
//============================================================================
char Controller::runMenu() {
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
					return PLAY_GAME;
				case QUIT_GAME:
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
	return 'q';
}
//============================================================================
void Controller::runGame() {
	this->m_gameState.levelup(90);
	this->seperateGameObjects(this->m_board.loadNewLevel());
	while (this->m_window.isOpen()){

				this->m_window.clear();
				this->m_gameState.draw(this->m_window);
				this->m_board.draw(m_window);
				this->drawObjects();
				this->m_window.display();

				sf::Event event = {};
				while (m_window.pollEvent(event)) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						m_window.close();
				}
				if (this->m_gameState.isTimeUp())
					this->resetLevel();
				sf::Time deltaTime = m_clock.restart();
				this->play_turns(deltaTime);
				this->checkColisions();
	}
}
//============================================================================
void Controller::play_turns(const sf::Time& deltaTime) {
	//the player is playing:
	this->m_player->playTurn(deltaTime, this->m_board);
	
	this->enemiesTurns(deltaTime);
}
//============================================================================
void Controller::enemiesTurns(const sf::Time& deltaTime) {
	for (int i = 0; i < this->m_enemies.size(); i++) 
		this->m_enemies[i]->playTurn(deltaTime, this->m_board);
}
//============================================================================
void Controller::drawObjects() {
	this->m_player->draw(this->m_window);
	for (int i = 0; i < this->m_enemies.size(); ++i)
		this->m_enemies[i]->draw(this->m_window);
}
//============================================================================
void Controller::seperateGameObjects(const vector<MovingObject*>& list) {
	for (int i = 0; i < list.size(); ++i) {
		if (dynamic_cast <Player*> (list[i]))
			this->m_player = (Player*)list[i];
		else
			this->m_enemies.push_back(list[i]);
	}
}
//============================================================================
void Controller::resetLevel(){
	//reset Static objects:
	this->m_board.resetLvl(); 

	//reset MovingObjects:
	this->m_player->reset();
	for (int i = 0; i < this->m_enemies.size(); ++i)
		this->m_enemies[i]->reset();
	this->m_gameState.died();
}
//============================================================================
void Controller::gameOver() {
	this->m_board.gameOver();
	//this->run();
}
//============================================================================
void Controller::checkColisions() {
	if (dynamic_cast <Coin*> (this->m_board.getContent(this->m_player->getCenter()))) {
		if (!((Coin*)this->m_board.getContent(this->m_player->getCenter()))->is_collected()) {
			((Coin*)this->m_board.getContent(this->m_player->getCenter()))->collect();
			this->m_gameState.collectedCoin();
		}
	}
	for (int i = 0; i < this->m_enemies.size(); i++) {
		if (this->m_player->CollidesWith(*this->m_enemies[i])) {
			this->m_gameState.died();
				if (this->m_gameState.isGameOver()) 
					this->gameOver();
				else{
					this->resetLevel();
				}
				break;
		}
	}
}
//============================ private section ===============================
//============================== gets section ================================
//============================ methods section ===============================