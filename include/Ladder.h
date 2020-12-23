#pragma once

class Ladder
{
public:
	Ladder();
	virtual void draw();
	virtual char identify()const;
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);
	virtual int getState()const;

private:
	virtual void setState(const int);
	virtual void setSprite(const sf::Sprite&);
};
{
}