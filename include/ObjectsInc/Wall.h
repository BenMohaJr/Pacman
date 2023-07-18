#pragma once
#include "ObjectsInc/StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(double sizeScale, sf::Vector2f position);
	~Wall() {}

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Ghost& gameObject);

private:
	sf::Sprite m_wall;
};
