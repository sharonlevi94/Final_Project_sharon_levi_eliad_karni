#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(
		const sf::Vector2f location = sf::Vector2f(0,0), 
		const sf::Vector2f size = sf::Vector2f(OBJ_WIDTH, OBJ_HEIGHT), 
		int state = STAND,
		const sf::Sprite& (*)(char) = nullptr,
		char type = NULL);

	virtual void draw(sf::RenderWindow&, const sf::Texture&)const override;
	//virtual char identify() const override;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) override;
	virtual void reset(const sf::Vector2f& )override;
	virtual void addSprite(const sf::Sprite&)override;
	void dig();


private:
	virtual void setState(const int);
	virtual void setSprite(const sf::Sprite&);
	int m_digState;

};
