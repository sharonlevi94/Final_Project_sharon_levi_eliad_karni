//============================= include section ==============================
#include "Gift.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Gift::Gift(const sf::Vector2f& location,
	const sf::Vector2f& size)
	:CollectableObject(location, size, GIFT_T) {
}