#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include "Macros.h"
//========================== forward declarations ============================
class Wall;
class Ladder;
class Coin;
class Player;
class Enemy;
class Rod;
class Board;

class GameObject{
public:
	GameObject(
		const sf::Vector2f = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0),
		char objectType = NOTHING);

	virtual void draw(sf::RenderWindow& window);
	virtual void playTurn(const sf::Time&, const Board&) = 0;
	virtual void reset();

	bool CollidesWith(const GameObject&)const;
	
	sf::Vector2f getAbove()const;
	sf::Vector2f getLeft()const;
	sf::Vector2f getBelow()const;
	sf::Vector2f getRight()const;
	sf::Vector2f getCenter()const;
	sf::Vector2f getBotLeft()const;
	sf::Vector2f getBotRight()const;

	const sf::Vector2f& getLocation()const;
	sf::Vector2f getSize()const;
	int getState ()const;
	const sf::Sprite& getSprite()const;

	void setState(int);
protected:
	virtual void setLocation(const sf::Vector2f&);
private:
	sf::Sprite m_objectSprite;
	int m_state;
};