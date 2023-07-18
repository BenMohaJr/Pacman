#include "ObjectsInc/ExtraTimeGift.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Ghost.h"


ExtraTimeGift::ExtraTimeGift(double sizeScale, sf::Vector2f position)
	: Gift(EXTRA_TIME, sizeScale, position) {}

// Double Dispatch.
void ExtraTimeGift::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void ExtraTimeGift::handleCollision(Pacman& gameObject)
{
	gameObject.handleCollision(*this);
}
void ExtraTimeGift::handleCollision(Ghost& gameObject)
{
	gameObject.handleCollision(*this);
}