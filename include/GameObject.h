#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;
class GameObject
{
public:
	GameObject(const sf::Vector2f location, const sf::Vector2f size, int state);
	virtual void draw() const;
	virtual char identify()const;
	virtual void playTurn(char (*)(const sf::Vector2f&));
	virtual void reset(const sf::Vector2f&);

	const sf::Vector2f& getLocation()const;
	const sf::Vector2f& getSize()const;
	const int getState()const;
	const sf::Sprite* getSprite()const;

private:
	sf::Vector2f m_location;
	sf::Vector2f m_size;
	int m_state;
	vector<sf::Sprite*> m_sprites;

	virtual void setState(const int);
	virtual void setLocation(const sf::Vector2f&);
	virtual void setSprite(const sf::Sprite&);
};