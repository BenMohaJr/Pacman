#pragma once

#include "Ghost.h"

class SmartGhost : public Ghost
{
public:
	SmartGhost(double sizeScale, sf::Vector2f position);
	~SmartGhost() = default;

	void move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>>& StaticObject, sf::Time deltaTime);

private:
};

