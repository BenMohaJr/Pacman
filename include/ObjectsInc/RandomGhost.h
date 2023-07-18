#pragma once

#include "Ghost.h"


class RandomGhost : public Ghost
{
public:
	RandomGhost(double sizeScale, sf::Vector2f position);
	~RandomGhost() = default;

	void move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>>& StaticObject, sf::Time deltaTime);

private:
	int m_direction;
};


