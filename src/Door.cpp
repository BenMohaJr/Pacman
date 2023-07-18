#include "ObjectsInc/Door.h"
#include "ObjectsInc/Ghost.h"
#include "ObjectsInc/Pacman.h"


Door::Door(double sizeScale, sf::Vector2f position)
	: StaticObject(DOOR, sizeScale, position) {}

// A connector between the door and the key.
void Door::setKey(Key* key)
{
	m_key = key;
}
// Disconnects the key in case it is deleted.
void Door::Dispose()
{
	m_isDisposed = true;
	m_key->setNull();
}

// Double Dispatch.
void Door::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void Door::handleCollision(Pacman& gameObject)
{
	gameObject.handleCollision(*this);
}
void Door::handleCollision(Ghost& gameObject)
{
	gameObject.handleCollision(*this);
}
