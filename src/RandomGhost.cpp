#include "ObjectsInc/RandomGhost.h"


RandomGhost::RandomGhost(double sizeScale, sf::Vector2f position)
	: Ghost(RANDOM_GHOST, sizeScale, position), m_direction(0) {}


// A random move that shoots a direction and goes 200 steps or until it gets stuck in a wall.
void RandomGhost::move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>>& StaticObject, sf::Time deltaTime)
{
	static int counter = 0;

	if(counter == 0 || m_object.getPosition() == m_lastLocation){
		m_direction = rand() % 4;
		counter += 200;
	}
	else
		m_lastLocation = m_object.getPosition();

	sf::Vector2f direction;
	switch (m_direction)
	{
	case 0:
			direction = sf::Vector2f(-1, 0);
		break;

	case 1:
			direction = sf::Vector2f(1, 0);
		break;

	case 2:
			direction = sf::Vector2f(0, -1);
		break;

	case 3:
			direction = sf::Vector2f(0, 1);
		break;
	}
	m_object.move(direction * (speedPerSecond - 20.f) * deltaTime.asSeconds());
	counter--;

	auto row = m_object.getPosition().x;
	auto col = m_object.getPosition().y;

	if (row > distance + boardWidth - (sizeObject * m_object.getScale().y))
		row = distance + (sizeObject * m_object.getScale().y);
	else if (row < distance + (sizeObject * m_object.getScale().y))
		row = boardWidth + distance - (sizeObject * m_object.getScale().y);
	if (col > distance + boardLength - (sizeObject * m_object.getScale().y))
		col = distance + (sizeObject * m_object.getScale().y);
	else if (col < distance + (sizeObject * m_object.getScale().y))
		col = boardLength + distance - (sizeObject * m_object.getScale().y);

	m_object.setPosition(sf::Vector2f(row, col));
}