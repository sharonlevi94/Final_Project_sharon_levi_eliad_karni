#pragma once
#include "Enemy.h"
class SmartEnemy: public Enemy
{
public:
	//using MovingObject::GameObject;
	SmartEnemy(const sf::Vector2f location,
		const sf::Vector2f size,
		int state,
		const sf::Sprite& (*)(char),
		char type);

	virtual void draw(sf::RenderWindow&, const sf::Texture&) const override;
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