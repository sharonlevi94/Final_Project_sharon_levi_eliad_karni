#pragma once
#include <SFML/Graphics.hpp>
#include "EffectsHolder.h"
#include <vector>
#include "Macros.h"
using std::vector;
class GameObject
{
public:
	GameObject(
		const sf::Vector2f = sf::Vector2f(0,0),
		int = STAND,
		const EffectsHolder& = EffectsHolder());
	                                      
	virtual void draw()const = 0;
	virtual void playTurn() = 0;
	virtual void reset(const sf::Vector2f&) = 0;

	const sf::Vector2f& getLocation()const;
	int                 getState   ()const;

	
private:
	sf::Sprite m_objectSprite;
	int                   m_state;

	virtual void setState (const int)=0;
	virtual void setTexture (const sf::Texture&)=0;
	virtual void setLocation(const sf::Vector2f& movment);
};