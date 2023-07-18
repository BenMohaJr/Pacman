#include "ObjectsInc/key.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Ghost.h"

Key::Key(double sizeScale, sf::Vector2f position)
	: StaticObject(KEY, sizeScale, position) {}

// A connector between the key and the door.
void Key::setDoor(Door* door)
{
	m_door = door;
}
// Disconnects the door if it has been deleted.
void Key::setNull()
{
	m_door = NULL;
}
// Also deletes the door if it is not deleted.
void Key::Dispose()
{
	m_isDisposed = true;
	if(m_door != NULL)
		m_door->Dispose();
}

// Double Dispatch.
void Key::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void Key::handleCollision(Pacman& gameObject)
{
	gameObject.handleCollision(*this);
}
void Key::handleCollision(Ghost& gameObject)
{
	gameObject.handleCollision(*this);
}
