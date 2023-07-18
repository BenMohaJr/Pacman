#include "ObjectsInc/Ghost.h"


// There are 3 Ghost inheritor classes that each implement a mov function.
Ghost::Ghost(OBJECTS object, double sizeScale, sf::Vector2f position)
	: MovingObject(object, sizeScale, position) {}

// Moves the Ghost towards the pacman.
void Ghost::relocate(Direction dir, int row, int col, sf::Time deltaTime) {
	sf::Vector2f direction;
	switch (dir)//decider
	{
	case X:
		if (row < 0)
			direction = sf::Vector2f(-1, 0);
		else
			direction = sf::Vector2f(1, 0);
		break;

	case Y:
		if (col < 0)
			direction = sf::Vector2f(0, -1);
		else
			direction = sf::Vector2f(0, 1);
		break;
	}
	m_object.move(direction * speedPerSecond * deltaTime.asSeconds());
}

//  Checking in relation to Pacman which is closer in rows or columns.
void Ghost::decideWhereToGo(int x, int y, Direction& shortD, Direction& longD)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x < 10)
	{
		shortD = Y;
		longD = X;
	}
	else if (y < 10)
		{
			shortD = X;
			longD = Y;
		}
	else if (x > y)
		{
			shortD = Y;
			longD = X;
		}
	else
	{
		shortD = X;
		longD = Y;
	}
}

//Double Dispatch.
void Ghost::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}

void Ghost::handleCollision(Pacman& gameObject)
{}

void Ghost::handleCollision(Wall& gameObject)
{
	m_object.setPosition(m_lastLocation);
}
void Ghost::handleCollision(Door& gameObject)
{
	m_object.setPosition(m_lastLocation);
}

