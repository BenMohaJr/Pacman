#include "ObjectsInc/Wall.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Ghost.h"

Wall::Wall(double sizeScale, sf::Vector2f position)
	: StaticObject(WALL, sizeScale, position) {}

//Double Dispatch.
void Wall::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void Wall::handleCollision(Pacman& gameObject)
{
	gameObject.handleCollision(*this);
}
void Wall::handleCollision(Ghost& gameObject)
{
	gameObject.handleCollision(*this);
}
