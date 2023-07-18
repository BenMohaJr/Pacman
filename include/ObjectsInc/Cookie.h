#pragma once
#include "ObjectsInc/StaticObject.h"


class Cookie : public StaticObject
{
public:
	Cookie(double sizeScale, sf::Vector2f position);
	~Cookie() {}

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Ghost& gameObject);

private:

};

