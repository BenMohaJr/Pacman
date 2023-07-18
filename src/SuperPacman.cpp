#include "ObjectsInc/SuperPacman.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Door.h"
#include "ObjectsInc/Ghost.h"

// The state class that handles the collision with a door and 
// an ghost when the user is in Super Pacman mode

SuperPacman::SuperPacman(){
	m_ghostSound.setBuffer(*Resources::instance().getSound(GHOST_SUPER));
	m_doorSound.setBuffer(*Resources::instance().getSound(DOOR_SUPER));
}

void SuperPacman::ChangeOfState(Pacman& pacman) {
	if (!GameData::instance().getSuper())
		pacman.downgradeToNormal();
}

void SuperPacman::handleDoorCollision(Pacman& pacman, Door& door)
{
	if (GameData::instance().collisionseIsMute())
		m_doorSound.play();
	door.Dispose();
}
void SuperPacman::handleGhostCollision(Ghost& ghost, std::function<void()> resetMovingObj)
{
	if (GameData::instance().collisionseIsMute())
		m_ghostSound.play();
	ghost.reset();
}