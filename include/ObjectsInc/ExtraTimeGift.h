#pragma once
#include "ObjectsInc/Gift.h"

class ExtraTimeGift : public Gift
{
public:
	ExtraTimeGift(double sizeScale, sf::Vector2f position);
	~ExtraTimeGift() = default;

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Ghost& gameObject);

private:

};



