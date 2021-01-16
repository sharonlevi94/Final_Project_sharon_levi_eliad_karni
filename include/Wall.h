#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>

class MovingObject;

class Wall : public StaticObject
{
public:
	Wall(const sf::Vector2f = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));

	void playTurn(const sf::Time&, Board&) override;
	virtual void draw(sf::RenderWindow&, const sf::Time&);
	void getDigged();
	void unDigg(const sf::Time&);

	bool isDigged()const;

private:
	bool m_isDigged;
	sf::Time m_diggedTime;
};
