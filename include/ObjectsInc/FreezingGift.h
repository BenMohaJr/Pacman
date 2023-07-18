#pragma once
#include "ObjectsInc/Gift.h"

class FreezingGift : public Gift
{
public:
	FreezingGift(double sizeScale, sf::Vector2f position);
	~FreezingGift() = default;

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Pacman& gameObject);
	virtual void handleCollision(Ghost& gameObject);

private:


};