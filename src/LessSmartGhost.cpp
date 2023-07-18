#include "ObjectsInc/LessSmartGhost.h"


LessSmartGhost::LessSmartGhost(double sizeScale, sf::Vector2f position)
	: Ghost(LESS_SMART_GHOST, sizeScale, position) {}

// A less smart move that only checks one direction it went and doesn't check if it failed.
void LessSmartGhost::move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>>& StaticObject, sf::Time deltaTime)
{
	m_lastLocation = m_object.getPosition();
	int row = pacmanLocation.x - m_object.getPosition().x;
	int col = pacmanLocation.y - m_object.getPosition().y;
	Direction shortD;
	Direction longD;

	decideWhereToGo(row, col, shortD, longD);

	relocate(shortD, row, col, deltaTime);
}