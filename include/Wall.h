#pragma once
//============================ include section ===============================
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
//========================== forward declarations ============================
class MovingObject;
/*============================================================================*/
class Wall : public StaticObject
{
public:
	//========================== public section ==============================
	 //================= constractors and destractors section =================
	Wall(const sf::Vector2f & = sf::Vector2f(0,0),
		const sf::Vector2f& = sf::Vector2f(0,0));
	//=========================== method section ==============================
	virtual void draw(sf::RenderWindow&);
	virtual void reset()override;
	virtual void handleCollision(MovingObject&, const sf::Vector2f&)override;
	void dig(const sf::Time&);
	void unDigg(const sf::Time&);
	void changeTrapMode(bool);
	bool isDigged()const;
	//============================ gets section ===============================
	bool getTrappingState()const;
	//========================= private section ===============================
private:
	//========================= members section ===============================
	bool m_isDigged;
	bool m_isTrapping;
	sf::Time m_diggedTime;
};
//============================ include section ===============================
//========================== forward declarations ============================
//============================== using section ===============================
/*============================================================================
* Class:
 ============================================================================*/
 //========================== public section ==============================
 //================= constractors and destractors section =================
//============================ gets section ===============================
//=========================== method section ==============================
//========================= private section ===============================
//========================= members section ===============================
//====================== privete methods section ==========================