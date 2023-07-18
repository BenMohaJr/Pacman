#pragma once
#include "StaticObject.h"

class Gift : public StaticObject
{
public:
	// using StaticObject::StaticObject;
	Gift(OBJECTS object, double sizeScale, sf::Vector2f position);
	virtual ~Gift() {}

	virtual void handleCollision(Object& gameObject) = 0;
	virtual void handleCollision(Pacman& gameObject) = 0;
	virtual void handleCollision(Ghost& gameObject) = 0;

protected:
};
