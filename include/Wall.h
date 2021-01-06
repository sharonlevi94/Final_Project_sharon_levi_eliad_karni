#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	using StaticObject::StaticObject;

	virtual void draw(sf::RenderWindow&, const sf::Texture&)const override;
	//virtual int identify() const override;
	// void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
//	virtual void reset(const sf::Vector2f& )override;
	//virtual void addSprite(const sf::Sprite&)override;
	void dig();

private:
	//virtual void setState(const int);
	//virtual void setSprite(const sf::Sprite&);
	int m_digState;

};
