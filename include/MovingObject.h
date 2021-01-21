#pragma once
//============================ include section ===============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class Wall;
class Ladder;
class Coin;
class Rod;
class Board;
class StaticObject;

class MovingObject : public GameObject
{
public:
	MovingObject(const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0),
		char objectType = NOTHING);

	virtual void playTurn(const sf::Time&, Board&) = 0;
	const Wall& getTrappingWall()const;
	sf::Vector2f getInitialLoc()const;
	int getLookState()const;
	
	virtual bool physicsTurn(const sf::Time&, Board&);
	void moveUp(const sf::Time&, Board&);
	void moveDown(const sf::Time&, Board&);
	void moveLeft(const sf::Time&, Board&);
	void moveRight(const sf::Time&, Board&);
	virtual void nullMovement(const sf::Vector2f&);

	virtual void handleCollision(const Ladder&, const sf::Vector2f&);
	virtual void handleCollision(Wall&, const sf::Vector2f&);
	virtual void handleCollision(const Rod&, const sf::Vector2f&);
	virtual void handleCollision(const StaticObject&, const sf::Vector2f&);

	void getTrapped(Wall*);
	void getUntrapped();
	bool getTrapState()const;

	bool isFalling(const Board&);
	virtual void setLocation(const sf::Vector2f&);
	void setLookState(int);
	virtual void reset()override;
	virtual void setState(int)override;
private:
	sf::Vector2f m_initialLoc;
	int m_lookingState;
	bool m_isTrapped;
	Wall* m_trappingWall;

	
};