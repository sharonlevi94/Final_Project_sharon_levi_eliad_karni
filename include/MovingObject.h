#pragma once
//============================ include section ===============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class Board;

class MovingObject : public GameObject
{
public:
	MovingObject(const sf::Vector2f = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0),
		char objectType = NOTHING);

	sf::Vector2f getInitialLoc()const;
	int getLookState()const;

	void moveUp(const sf::Time&, Board&);
	void moveDown(const sf::Time&, Board&);
	void moveLeft(const sf::Time&, Board&);
	void moveRight(const sf::Time&, Board&);

	bool isFalling(const Board&);
	virtual void setLocation(const sf::Vector2f&);
	void setLookState(int);
	virtual void reset()override;

private:
	sf::Vector2f m_initialLoc;
	int m_lookingState;
	bool m_isTrapped;
};