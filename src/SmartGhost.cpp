#include "ObjectsInc/SmartGhost.h"


SmartGhost::SmartGhost(double sizeScale, sf::Vector2f position)
	: Ghost(SMART_GHOST, sizeScale, position) {}


// A smart move that checks if one direction she went in fails and goes in the other direction.
void SmartGhost::move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>>& StaticObject, sf::Time deltaTime)
{
	m_lastLocation = m_object.getPosition();
	int row = pacmanLocation.x - m_object.getPosition().x;
	int col = pacmanLocation.y - m_object.getPosition().y;
	Direction shortD;
	Direction longD;

	decideWhereToGo(row, col, shortD, longD);

	relocate(shortD, row, col, deltaTime);

	for (int i = 0; i < StaticObject.size(); i++)
		if (this->getGlobalBounds().intersects(StaticObject[i]->getGlobalBounds()))
			StaticObject[i]->handleCollision(*this);

	if (m_object.getPosition() == m_lastLocation)
		relocate(longD, row, col, deltaTime);
}