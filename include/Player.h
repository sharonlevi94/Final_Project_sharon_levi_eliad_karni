#pragma once
#include "MovingObject.h"
#include "Wall.h"
class Player : public MovingObject
{
public:
	//using MovingObject::GameObject;
	Player(const sf::Vector2f location = sf::Vector2f(0, 0),
		const sf::Vector2f size = sf::Vector2f(OBJ_WIDTH, OBJ_HEIGHT),
		int state = STAND,
		const sf::Sprite& (*)(char) = nullptr,
		char type = '\0');

	virtual char identify() const override;
	virtual sf::Drawable draw() const override;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	virtual void reset(const sf::Vector2f&) override;
	virtual void addSprite(const sf::Sprite&)override;

	virtual void fall(int) override;
	virtual bool isMovePossible()const  override;

	void dig(Wall&);

private:

	virtual void setState(const int) override;
	virtual void setLocation(const sf::Vector2f&) override;
	virtual void setSprite(const sf::Sprite&) override;
};