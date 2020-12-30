#pragma once
#include <SFML/Graphics.hpp>
#include "EffectsHolder.h"
#include <vector>
using std::vector;
class GameObject
{
public:
	GameObject(
		const sf::Vector2f location = sf::Vector2f(0,0), 
		const sf::Vector2f size = sf::Vector2f(0, 0), 
		int state = 0,
		const sf::Sprite& (*)(char) = nullptr,
		char type = '\0');
	virtual ~GameObject();

	virtual void draw     ()const=0;
	virtual char identify ()const=0;
	virtual void playTurn (const GameObject* (*)(const sf::Vector2f&));
	virtual void reset    (const sf::Vector2f&);

	const sf::Vector2f& getLocation()const;
	const sf::Vector2f& getSize    ()const;
	int                 getState   ()const;
	const sf::Sprite*   getSprite  ()const;
	char identify()const;
	void addSprite(const sf::Sprite& (*)(char));

private:
	char m_type;
	sf::Vector2f       m_location;
	sf::Vector2f           m_size;
	int                   m_state;
	vector<sf::Sprite*> m_sprites;
	

	virtual void setState              (const int);
	virtual void setLocation (const sf::Vector2f&);
	virtual void setSprite     (const sf::Sprite&);
	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
};