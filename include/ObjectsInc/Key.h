#pragma once
#include "ObjectsInc/StaticObject.h"

class Key : public StaticObject
{
public:
	Key(double sizeScale, sf::Vector2f position);
	~Key() {}

	void setDoor(Door* door);
	void setNull();
	void Dispose() override;

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Ghost& gameObject);

private:
	Door* m_door;
};

