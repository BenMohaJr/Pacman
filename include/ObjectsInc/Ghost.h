#pragma once
#include "ObjectsInc/MovingObject.h"
#include "Pacman.h"

//enum for which direction we want to go
enum Direction {
	X = 0,
	Y = 1
};

class Ghost : public MovingObject
{
public:
	Ghost(OBJECTS object, double sizeScale, sf::Vector2f position);
	virtual ~Ghost() {}

	virtual void move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>> &StaticObject, sf::Time deltaTime) = 0;
	void relocate(Direction direction, int row, int col, sf::Time deltaTime);
	void decideWhereToGo(int x, int y, Direction& shortD, Direction& longD);

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Wall& gameObject);
	virtual void handleCollision(Door& gameObject);
	virtual void handleCollision(Key& gameObject) {}
	virtual void handleCollision(Cookie& gameObject) {}
	virtual void handleCollision(Ghost& gameObject) {}
	virtual void handleCollision(ExtraLifeGift& gameObject) {}
	virtual void handleCollision(ExtraTimeGift& gameObject) {}
	virtual void handleCollision(FreezingGift& gameObject) {}
	virtual void handleCollision(SuperPacmanGift& gameObject) {}

protected:
};
