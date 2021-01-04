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
		const sf::Vector2f location = sf::Vector2f(0,0), 
		const sf::Vector2f size = sf::Vector2f(OBJ_WIDTH, OBJ_HEIGHT), 
		int state = STAND,
	    sf::Texture* = nullptr,
		char type = NULL);

	virtual ~GameObject();
	                                      
	virtual sf::Drawable draw()const = 0;
	char identify ()const;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) = 0;
	virtual void reset(const sf::Vector2f&) = 0;
	virtual void addSprite(const sf::Sprite&)=0;

	const sf::Vector2f& getLocation()const;
	const sf::Vector2f& getSize    ()const;
	int                 getState   ()const;
	const sf::Sprite*   getSprite  ()const;
	
private:
	char m_type;
	sf::Vector2f       m_location;
	sf::Vector2f           m_size;
	int                   m_state;
	sf::Texture*        m_textures;

	virtual void setState (const int)=0;
	virtual void setSprite (const sf::Sprite&)=0;
};