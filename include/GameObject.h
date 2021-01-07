#pragma once
#include <SFML/Graphics.hpp>
#include "EffectsHolder.h"
#include "Board.h"
#include <vector>
#include "Macros.h"
using std::vector;
class GameObject
{
public:
	GameObject(
		const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0),
		char objectType = NOTHING);
	                                      
	virtual void draw(sf::RenderWindow& window);
	virtual void playTurn(const Board&) = 0;
	virtual void reset();

	const sf::Vector2f& getLocation()const;
	const sf::Vector2f& getSize()const;
	int getState ()const;
	const sf::Sprite& getSprite()const;

protected:
	virtual void setLocation(const sf::Vector2f&);
private:
	sf::Sprite m_objectSprite;
	int m_state;

	//virtual void setState (const int)=0;
	//virtual void setTexture (const sf::Texture&)=0;
};