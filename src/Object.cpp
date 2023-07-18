#include "ObjectsInc/Object.h"

// A basic constructor used by all objects.
Object::Object(OBJECTS object, double sizeScale, sf::Vector2f position)
{
	m_object.setTexture(*Resources::instance().getObjects(object));
	m_object.setScale(sizeScale, sizeScale);
	m_object.setPosition(position);
}

sf::FloatRect Object::getGlobalBounds() const
{
	return m_object.getGlobalBounds();
}

void Object::drawObject(sf::RenderWindow& window) const
{
	window.draw(m_object);
}
