#pragma once
#include "ObjectsInc/StaticObject.h"


class Door : public StaticObject
{
public:
	Door(double sizeScale, sf::Vector2f position);
	~Door() {}

	void Dispose() override;
	void setKey(Key* key);

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Ghost& gameObject);

private:
	Key* m_key;
};


