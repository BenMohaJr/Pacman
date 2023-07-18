#pragma once
#include "ObjectsInc/Gift.h"


class SuperPacmanGift : public Gift
{
public:
	SuperPacmanGift(double sizeScale, sf::Vector2f position);
	~SuperPacmanGift() = default;

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Ghost& gameObject);

private:

};

