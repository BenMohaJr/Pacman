#include "ObjectsInc/Cookie.h"
#include "ObjectsInc/Gift.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Ghost.h"

Cookie::Cookie(double sizeScale, sf::Vector2f position)
	: StaticObject(COOKIE, sizeScale, position) {}

// Double Dispatch.
void Cookie::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void Cookie::handleCollision(Pacman& gameObject)
{
	gameObject.handleCollision(*this);
}
void Cookie::handleCollision(Ghost& gameObject)
{
	gameObject.handleCollision(*this);
}

