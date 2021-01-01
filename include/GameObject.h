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
		const sf::Sprite& (*)(char) = nullptr,
		char type = '\0');

	virtual ~GameObject();

	virtual sf::Drawable draw()const = 0;
	virtual char identify ()const = 0;
	virtual void playTurn(const GameObject* (*)(const sf::Vector2f&)) = 0;
	virtual void reset(const sf::Vector2f&) = 0;
	void addSprite(const sf::Sprite& (*)(char)) = 0;

	const sf::Vector2f& getLocation()const;
	const sf::Vector2f& getSize    ()const;
	int                 getState   ()const;
	const sf::Sprite*   getSprite  ()const;
	
private:
	char m_type;
	sf::Vector2f       m_location;
	sf::Vector2f           m_size;
	int                   m_state;
	vector<sf::Sprite*> m_sprites;

	virtual void setState              (const int)=0;
	virtual void setLocation (const sf::Vector2f&)=0;
	virtual void setSprite     (const sf::Sprite&)=0;
};