#include "ObjectsInc/NormalPacman.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Door.h"
#include "ObjectsInc/Ghost.h"

// The state class that handles the collision with a door and 
// an ghost when the user is in Pacman mode

NormalPacman::NormalPacman(){
	m_ghostSound.setBuffer(*Resources::instance().getSound(GHOST_PACMAN));
}

void NormalPacman::ChangeOfState(Pacman& pacman) {
	if (GameData::instance().getSuper())
		pacman.upgradeToSuper();
}

void NormalPacman::handleDoorCollision(Pacman& pacman, Door& door)
{
	pacman.dontMove();
}
void NormalPacman::handleGhostCollision(Ghost& ghost, std::function<void()> resetMovingObj)
{
	if (GameData::instance().collisionseIsMute())
		m_ghostSound.play();
	GameData::instance().setLife(-1);
	resetMovingObj();
}