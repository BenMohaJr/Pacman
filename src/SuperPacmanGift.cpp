#include "ObjectsInc/SuperPacmanGift.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Ghost.h"

SuperPacmanGift::SuperPacmanGift(double sizeScale, sf::Vector2f position)
	: Gift(SUPER_PACMAN_GIFT, sizeScale, position) {}

//Double Dispatch
void SuperPacmanGift::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void SuperPacmanGift::handleCollision(Pacman& gameObject)
{
	gameObject.handleCollision(*this);
}
void SuperPacmanGift::handleCollision(Ghost& gameObject)
{
	gameObject.handleCollision(*this);
}

