#pragma once
#include "MovingObject.h"
#include "Wall.h"

class Player : public MovingObject
{
public:
	using MovingObject::MovingObject;
	//virtual char identify() const override;
	virtual void draw(sf::RenderWindow& ,const sf::Texture&) const;
	//virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	//virtual void reset(const sf::Vector2f&) override;
	//virtual void addSprite(const sf::Sprite&)override;

	//virtual void fall(int) override;
	//virtual bool isMovePossible()const  override;

	//void dig(Wall&);

private:
	//virtual void setState(const int) override;
	//virtual void setLocation(const sf::Vector2f&) override;
	//virtual void setSprite(const sf::Sprite&) override;
};