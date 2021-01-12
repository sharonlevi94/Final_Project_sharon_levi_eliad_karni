#pragma once
//============================ include section ===============================
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class Board;

class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;
	MovingObject(const sf::Vector2f = sf::Vector2f(0, 0),
		const EffectsHolder & = EffectsHolder(),
		const sf::Vector2f & = sf::Vector2f(0, 0));

	sf::Vector2f getAbove()const;
	sf::Vector2f getLeft()const;
	sf::Vector2f getBelow()const;
	sf::Vector2f getRight()const;
	sf::Vector2f getCenter()const;
	sf::Vector2f getInitialLoc()const;

	void moveUp(const sf::Time&, const Board&);
	void moveDown(const sf::Time&, const Board&);
	void moveLeft(const sf::Time&, const Board&);
	void moveRight(const sf::Time&, const Board&);

	bool isFalling(const Board&);
	virtual void setLocation(const sf::Vector2f&);

private:
	sf::Vector2f m_initialLoc;
};