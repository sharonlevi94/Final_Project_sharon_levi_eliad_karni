#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#pragma once
#include "Utilities.h"
#include "Macros.h"
class GameObject
{
public:
	GameObject(
		const sf::Vector2f = sf::Vector2f(0,0),
		const EffectsHolder& = EffectsHolder(),
		const sf::Vector2f& = sf::Vector2f(0,0),
		char objectType = NOTHING);
	                                      
	virtual void draw(sf::RenderWindow& window);
	virtual void playTurn() = 0;
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
};
#endif //_GAMEOBJECT_H