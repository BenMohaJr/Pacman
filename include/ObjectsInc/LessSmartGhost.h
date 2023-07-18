#pragma once

#include "Ghost.h"


class LessSmartGhost : public Ghost
{
public:
	LessSmartGhost(double sizeScale, sf::Vector2f position);
	~LessSmartGhost() = default;

	void move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>>& StaticObject, sf::Time deltaTime);

private:
};


