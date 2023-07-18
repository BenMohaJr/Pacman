#include "ObjectsInc/ExtraLifeGift.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Ghost.h"


ExtraLifeGift::ExtraLifeGift(double sizeScale, sf::Vector2f position)
	: Gift(EXTRA_LIFE, sizeScale, position) {}

// Double Dispatch.
void ExtraLifeGift::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void ExtraLifeGift::handleCollision(Pacman& gameObject)
{
	gameObject.handleCollision(*this);
}
void ExtraLifeGift::handleCollision(Ghost& gameObject)
{
	gameObject.handleCollision(*this);
}
