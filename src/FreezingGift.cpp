#include "ObjectsInc/FreezingGift.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Ghost.h"


FreezingGift::FreezingGift(double sizeScale, sf::Vector2f position)
	: Gift(FREEZING, sizeScale, position) {}

// Double Dispatch.
void FreezingGift::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void FreezingGift::handleCollision(Pacman& gameObject)
{
	gameObject.handleCollision(*this);
}
void FreezingGift::handleCollision(Ghost& gameObject)
{
	gameObject.handleCollision(*this);
}