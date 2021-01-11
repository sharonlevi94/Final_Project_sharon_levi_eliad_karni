#pragma once
#include "GameObject.h"
#include "Board.h"

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

	void moveUp(const sf::Time&, const Board&);
	void moveDown(const sf::Time&, const Board&);
	void moveLeft(const sf::Time&, const Board&);
	void moveRight(const sf::Time&, const Board&);
	void fall();

	bool isFalling(const Board&);

	virtual void setLocation(const sf::Vector2f&);
private:
};