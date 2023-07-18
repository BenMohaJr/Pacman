#pragma once
#include "PacmanState.h"

class Pacman;
class Door;
class Ghost;

class NormalPacman : public PacmanState
{
public:
	NormalPacman();
	~NormalPacman() = default;

	void ChangeOfState(Pacman& pacman);
	void handleDoorCollision(Pacman& pacman, Door& door);
	void handleGhostCollision(Ghost& ghost, std::function<void()> resetMovingObj);

private:
};
