#pragma once
#include "ObjectsInc/Object.h"

class Cookie;
class Door;
class Key;
class Wall;
class Pacman;
class Ghost;
class ExtraLifeGift;
class ExtraTimeGift;
class FreezingGift;
class SuperPacmanGift;

class StaticObject : public Object
{
public:
	using Object::Object;
	virtual ~StaticObject() {}

	virtual void Dispose();
	bool isDisposed();

	virtual void handleCollision(Object& gameObject) = 0;
	virtual void handleCollision(Pacman& gameObject) = 0;
	virtual void handleCollision(Ghost& gameObject) = 0;
	virtual void handleCollision(Cookie& gameObject) {}
	virtual void handleCollision(Door& gameObject) {}
	virtual void handleCollision(Key& gameObject) {}
	virtual void handleCollision(Wall& gameObject) {}
	virtual void handleCollision(ExtraLifeGift& gameObject) {}
	virtual void handleCollision(ExtraTimeGift& gameObject) {}
	virtual void handleCollision(FreezingGift& gameObject) {}
	virtual void handleCollision(SuperPacmanGift& gameObject) {}

protected:
	bool m_isDisposed = false;
};
