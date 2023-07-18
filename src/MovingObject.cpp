#include "ObjectsInc/MovingObject.h"


MovingObject::MovingObject(OBJECTS object, double sizeScale, sf::Vector2f position)
	: Object(object, sizeScale, position), m_lastLocation(position), m_startLocation(position)
{}

sf::Vector2f MovingObject::getPosition()
{
	return m_object.getPosition();
}

void MovingObject::reset()
{
	m_object.setPosition(m_startLocation);
}
