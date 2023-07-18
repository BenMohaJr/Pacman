#pragma once
#include "ObjectsInc/Gift.h"


class ExtraLifeGift : public Gift
{
public:
	ExtraLifeGift(double sizeScale, sf::Vector2f position);
	~ExtraLifeGift() = default;

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Ghost& gameObject);

private:

};

