#pragma once
#include "Enemy.h"
class SmartEnemy: public Enemy
{
public:
	using Enemy::Enemy;
	

	virtual void draw(sf::RenderWindow&) const override;
//	virtual char identify() const override;
	//virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	//virtual void reset(const sf::Vector2f&) override;
	//virtual void addSprite(const sf::Sprite&)override;

	//virtual void fall(int) override;
	//virtual bool isMovePossible()const  override;

private:

	//virtual void setState(const int) override;
//	virtual void setLocation(const sf::Vector2f&) override;
	//virtual void setSprite(const sf::Sprite&) override;
};