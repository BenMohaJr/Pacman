#pragma once
#include "ObjectsInc/Object.h"
#include "ObjectsInc/Cookie.h"
#include "ObjectsInc/Key.h"
#include "ObjectsInc/ExtraLifeGift.h"
#include "ObjectsInc/ExtraTimeGift.h"
#include "ObjectsInc/FreezingGift.h"
#include "ObjectsInc/SuperPacmanGift.h"
#include "ObjectsInc/Door.h"


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

class MovingObject : public Object
{
public:
	MovingObject(OBJECTS object, double sizeScale, sf::Vector2f position);
	virtual ~MovingObject() = default;
	virtual void move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>> &StaticObject, sf::Time deltaTime) = 0;
	sf::Vector2f getPosition();
	void reset();

	virtual void handleCollision(Object& gameObject) = 0;
	virtual void handleCollision(Cookie& gameObject) = 0;
	virtual void handleCollision(Door& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(Pacman& gameObject) = 0;
	virtual void handleCollision(Ghost& gameObject) = 0;
	virtual void handleCollision(ExtraLifeGift& gameObject) = 0;
	virtual void handleCollision(ExtraTimeGift& gameObject) = 0;
	virtual void handleCollision(FreezingGift& gameObject) = 0;
	virtual void handleCollision(SuperPacmanGift& gameObject) = 0;

protected:
	sf::Vector2f m_lastLocation;
	sf::Vector2f m_startLocation;
};

